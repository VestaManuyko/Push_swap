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

static void	sort_max(t_world *world, int pos)
{
	//ft_printf("sorting max\n");
	if (pos > 1 && pos <= world->a_len/2)
		world->rot.ra = pos -1;
	if (pos > 1 && pos > world->a_len/2)
		world->rot.rra = (world->a_len - pos) + 1;
	if (world->pos_b.max != 1)
	{
		if (world->pos_b.max <= world->b_len / 2)
			world->rot.rb = world->pos_b.max - 1;
		if (world->pos_b.max > world->b_len / 2)
			world->rot.rrb = (world->b_len - world->pos_b.max) + 1;
	}
	do_rotate_all(world);
	push_to_b(world);
}

static void	sort_min(t_world *world, int pos)
{
	//ft_printf("sorting min\n");
	if (pos > 1 && pos <= world->a_len/2)
		world->rot.ra = pos -1;
	if (pos > 1 && pos > world->a_len/2)
		world->rot.rra = (world->a_len - pos) + 1;
	if (world->pos_b.max != 1)
	{
		if (world->pos_b.max <= world->b_len / 2)
			world->rot.rb = world->pos_b.max - 1;
		if (world->pos_b.max > world->b_len / 2)
			world->rot.rrb = (world->b_len - world->pos_b.max) + 1;
	}
	if (pos == 1 && world->pos_b.max == 1)
	{
		push_to_b(world);
		rotate_b(world);
	}
	else
	{
		do_rotate_all(world);
		push_to_b(world);
	}
}

static void	sort_mid(t_world *world, int pos)
{
	int		pos_b;
	int		nbr;

	//ft_printf("sorting mid\n");
	nbr = get_nbr(world, pos);
	pos_b = get_pos_b(world, nbr);
	//ft_printf("The nbr to sort %d, the b_pos %d\n", nbr, pos_b);
	if (pos > 1 && pos <= world->a_len / 2)
		world->rot.ra = pos - 1;
	if (pos > 1 && pos > world->a_len / 2)
		world->rot.rra = (world->a_len - pos) + 1;
	if (pos_b <= world->b_len / 2)
		world->rot.rb = pos_b - 1;
	if (pos_b > world->b_len / 2)
		world->rot.rrb = (world->b_len - pos_b) + 1;
	//ft_printf("for mid sort: ra %d rra %d rb %d rrb %d\n", world->rot.ra, world->rot.rra, world->rot.rb, world->rot.rrb);
	do_rotate_all(world);
	push_to_b(world);
}

void	sort_to_b(t_world *world)
{
	int		pos;
	t_list	*node;
	int		minmax;

	pos = 0;
	node = *world->stack_a;
	minmax = 0;
	while (node && pos < world->pos_min_op)
	{
		init_to_0(world);
		//ft_printf("CUR_content %d, B_MAX %d B_MIN %d\n",*(int *)node->content, world->b.max, world->b.min);
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
