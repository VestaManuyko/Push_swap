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
	if (world->rot.ra)
	{
		if (world->rot.ra >= world->rot.rb)
			world->op = world->rot.ra;
		if (world->rot.rb > world->rot.ra)
			world->op = world->rot.rb;
	}
	if (world->rot.rrb)
		world->op += world->rot.rrb;
	if (world->rot.rra)
	{
		if (world->rot.rra >= world->rot.rrb)
			world->op = world->rot.rra;
		if (world->rot.rrb > world->rot.rra)
			world->op = world->rot.rrb;
	}
	if (world->rot.rb)
		world->op += world->rot.rb;
}

static void	count_max(t_world *world, int pos)
{
	if (pos <= world->a_len / 2)
		world->rot.ra = pos - 1;
	else
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
}

static void	count_min(t_world *world, int pos)
{
	if (pos <= world->a_len / 2)
		world->rot.ra = pos - 1;
	else
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
		node = node->next;
		pos++;
	}
}
