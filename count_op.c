/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:41:42 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/29 15:41:43 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_rot_op(t_world *world)
{
	int	forward;
	int	reverse;

	forward = 0;
	reverse = 0;
	if (world->rot.ra > 0 && world->rot.rb > 0)
	{
		if (world->rot.ra > world->rot.rb)
			forward = world->rot.ra;
		else
			forward = world->rot.rb;
	}
	else
		forward = world->rot.ra + world->rot.rb;
	if (world->rot.rra > 0 && world->rot.rrb > 0)
	{
		if (world->rot.rra > world->rot.rrb)
			reverse = world->rot.rra;
		else
			reverse = world->rot.rrb;
	}
	else
		reverse = world->rot.rra + world->rot.rrb;
	world->op = forward + reverse;
}

static void	count_max(t_world *world, int pos)
{
	if (pos > 1 && pos <= world->a_len / 2)
		world->rot.ra = pos - 1;
	if (pos > world->a_len / 2)
		world->rot.rra = (world->a_len - pos) + 1;
	if (world->pos_b.max != 1)
	{
		if (world->pos_b.max <= world->b_len / 2)
			world->rot.rb = world->pos_b.max - 1;
		else
			world->rot.rrb = (world->b_len - world->pos_b.max) + 1;
	}
	get_rot_op(world);
	world->op += 1;
	ft_printf("Counting max with ra %d, rra %d, rb %d, rrb %d\n", world->rot.ra, world->rot.rra, world->rot.rb, world->rot.rrb);
}

static void	count_min(t_world *world, int pos)
{
	if (pos > 1 && pos <= world->a_len / 2)
		world->rot.ra = pos - 1;
	if (pos > world->a_len / 2)
		world->rot.rra = (world->a_len - pos) + 1;
	if (world->pos_b.max != 1)
	{
		if (world->pos_b.max <= world->b_len / 2)
			world->rot.rb = world->pos_b.max - 1;
		else
			world->rot.rrb = (world->b_len - world->pos_b.max) + 1;
	}
	if (world->pos_b.max == 1)
		world->rot.rb = 1;
	get_rot_op(world);
	world->op += 1;
	ft_printf("Counting min with ra %d, rra %d, rb %d, rrb %d\n", world->rot.ra, world->rot.rra, world->rot.rb, world->rot.rrb);
}

int	get_pos_b(t_world *world, int nbr)
{
	t_list	*node;
	int		pos_b;
	int		b_nbr;

	b_nbr = 0;
	pos_b = 1;
	node = *world->stack_b;
	while (node)
	{
		if (*(int *)node->content < nbr && *(int *)node->content > b_nbr)
			b_nbr = *(int *)node->content;
		node = node->next;
	}
	node = *world->stack_b;
	while (node && *(int *)node->content != b_nbr)
	{
		pos_b++;
		node = node->next;
	}
	return(pos_b);
}

static void	count_mid(t_world *world, int pos, int nbr)
{
	int		pos_b;

	pos_b = get_pos_b(world, nbr);
	if (pos > 1 && pos <= world->a_len / 2)
		world->rot.ra = pos;
	if (pos > world->a_len / 2)
		world->rot.rra = (world->a_len - pos) + 1;
	if (pos_b <= world->b_len / 2)
		world->rot.rb = pos_b - 1;
	if (pos_b > world->b_len / 2)
		world->rot.rrb = (world->b_len - pos_b) + 1;
	get_rot_op(world);
	world->op += 1;
	ft_printf("Counting mid with ra %d, rra %d, rb %d, rrb %d\n", world->rot.ra, world->rot.rra, world->rot.rb, world->rot.rrb);
}

void	init_to_0(t_world *world)
{
	world->op = 0;
	world->rot.ra = 0;
	world->rot.rb = 0;
	world->rot.rra = 0;
	world->rot.rrb = 0;
	world->a_len = ft_lstsize(*world->stack_a);
	world->b_len = ft_lstsize(*world->stack_b);
}

void	find_cheap(t_world *world)
{
	t_list	*node;
	int		pos;
	int		nbr;

	pos = 1;
	node = *world->stack_a;
	while (node)
	{
		init_to_0(world);
		nbr = get_nbr(world, pos);
		if (*(int *)node->content > world->b.max)
			count_max(world, pos);
		if (*(int *)node->content < world->b.min)	
			count_min(world, pos);
		if (*(int *)node->content < world->b.max && *(int *)node->content > world->b.min)
			count_mid(world, pos, nbr);
		if (world->min_op == -1 || world->op < world->min_op)
		{
			world->min_op = world->op;
			world->pos_min_op = pos;
		}
		ft_printf("Content %d at pos %d, needed op %d, cur_min_op %d\n", *(int *)node->content, pos, world->op, world->min_op);
		node = node->next;
		pos++;
	}
}
