/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:37:22 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/08/01 15:37:22 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rotate(t_world *world)
{
	int	i;

	i = 0;
	if (!world->rot.ra)
		return ;
	if (world->rot.ra >= world->rot.rb)
	{
		while (world->rot.rb && i++ < world->rot.rb)
			rotate_all(world);
		while (i++ < world->rot.ra)
			rotate_a(world);
	}
	if (world->rot.rb > world->rot.ra)
	{
		i = 0;
		while (i++ < world->rot.ra)
			rotate_all(world);
		while (i++ < world->rot.rb)
			rotate_b(world);
	}
	i = 0;
	while (i++ < world->rot.rrb)
		rev_rotate_b(world);
}

void	do_rev_rotate(t_world *world)
{
	int	i;

	i = 0;
	if (!world->rot.rra)
		return ;
	if (world->rot.rra >= world->rot.rrb)
	{
		while (world->rot.rrb && i++ < world->rot.rrb)
			rev_rotate_all(world);
		while (i++ < world->rot.rra)
			rev_rotate_a(world);
	}
	if (world->rot.rrb > world->rot.rra)
	{
		i = 0;
		while (i++ < world->rot.rra)
			rev_rotate_all(world);
		while (i++ < world->rot.rrb)
			rev_rotate_b(world);
	}
	i = 0;
	while (i++ < world->rot.rb)
		rotate_b(world);
}

static void	sort_max(t_world *world, int pos)
{
	ft_printf("sorting max\n");
	ft_printf("sorting pos %d\n", pos);
	if (pos > 2 && pos <= world->a_len/2)
		world->rot.ra = pos -1;
	if (pos > 2 && pos > world->a_len/2)
		world->rot.rra = (world->a_len - pos) + 1;
	if (world->pos_b.max != 1)
	{
		if (world->pos_b.max <= world->b_len / 2)
			world->rot.rb = world->pos_b.max - 1;
		else
			world->rot.rrb = (world->b_len - world->pos_b.max) + 1;
	}
	do_rotate(world);
	do_rev_rotate(world);
	push_to_b(world);
}

static void	sort_min(t_world *world, int pos)
{
	ft_printf("sorting min\n");
	ft_printf("sorting pos %d\n", pos);
	if (pos > 2 && pos <= world->a_len/2)
		world->rot.ra = pos -1;
	if (pos > 2 && pos > world->a_len/2)
		world->rot.rra = (world->a_len - pos) + 1;
	if (world->pos_b.max != 1)
	{
		if (world->pos_b.max <= world->b_len / 2)
			world->rot.rb = world->pos_b.max - 1;
		else
			world->rot.rrb = (world->b_len - world->pos_b.max) + 1;
	}
	if (world->pos_b.max == 1)
	{
		push_to_b(world);
		rotate_b(world);
	}
	else
	{
		do_rotate(world);
		do_rev_rotate(world);
		push_to_b(world);
	}
}

static void	sort_mid(t_world *world, int pos)
{
	t_list	*node;
	int		pos_b;
	int		nbr;

	ft_printf("sorting mid\n");
	pos_b = 0;
	nbr = get_nbr(world, pos);
	node = *world->stack_b;
	while (node && nbr < *(int *)node->content)
	{
		node = node->next;
		pos_b++;
	}
	if (pos > 2 && pos <= world->a_len / 2)
		world->rot.ra = pos;
	if (pos > 2 && pos > world->a_len / 2)
		world->rot.rra = (world->a_len - pos) + 1;
	if (pos_b <= world->b_len / 2)
		world->rot.rb = pos - 1;
	if (pos_b > world->b_len / 2)
		world->rot.rrb = (world->b_len - pos) + 1;
	do_rotate(world);
	do_rev_rotate(world);
	push_to_b(world);
}

void	sort_to_b(t_world *world)
{
	int		pos;
	t_list	*node;
	int		minmax;

	pos = 0;
	node = *world->stack_a;
	while (node && pos < world->pos_min_op)
	{
		// ft_printf("list while sorting:\npos of element %d\n", pos);
		ft_printf("min_op_pos %d and cur_pos %d\n", world->pos_min_op, pos);
		ft_printf("Content %d, max: %d, min: %d\n", *(int *)node->content, world->b.max, world->b.min);
		init_to_0(world);
		if (*(int *)node->content > world->b.max)
			minmax = MAX;
		if (*(int *)node->content < world->b.min)
			minmax = MIN;
		if (*(int *)node->content < world->b.max && *(int *)node->content > world->b.min)
			minmax = 0;
		node = node->next;
		pos++;
	}
	if (minmax == MAX)
		sort_max(world, pos);
	if (minmax == MIN)
		sort_min(world, pos);
	if (!minmax)
		sort_mid(world, pos);
}
