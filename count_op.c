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
	if (world->rot.ra != 0)
	{
		if (world->rot.ra > world->rot.rb)
			world->op = world->rot.ra;
		if (world->rot.rrb != 0)
			world->op += world->rot.rrb;
		if (world->rot.rb > world->rot.ra)
			world->op = world->rot.rb;
	}
	if (world->rot.rra != 0)
	{
		if (world->rot.rra > world->rot.rrb)
			world->op = world->rot.rra;
		if (world->rot.rrb > world->rot.rra)
			world->op = world->rot.rrb;
		if (world->rot.rb != 0)
			world->op += world->rot.rb;
	}
}

static void	count_max(t_world *world, int pos)
{
	if (pos <= world->len / 2)
		world->rot.ra = pos - 1;
	else
		world->rot.rra = (world->len - pos) + 1;
	if (world->pos_b.max != 1)
	{
		if (world->pos_b.max <= world->len / 2)
			world->rot.rb = world->pos_b.max - 1;
		else
			world->rot.rrb = (world->len - world->pos_b.max) + 1;
	}
	get_rot_op(world);
	world->op += 1;
}

static void	count_min(t_world *world, int pos)
{
	if (pos <= world->len / 2)
		world->rot.ra = pos - 1;
	else
		world->rot.rra = (world->len - pos) + 1;
	if (world->pos_b.min != 1)
	{
		if (world->pos_b.min <= world->len / 2)
			world->rot.rb = world->pos_b.min - 1;
		else
			world->rot.rrb = (world->len - world->pos_b.min) + 1;
	}
	get_rot_op(world);
	world->op += 1;
}

static void	count_mid(t_world *world, int pos, int nbr)
{
	t_list	*node;
	int		pos_b;

	pos_b = 0;
	node = *world->stack_b;
	while (node && nbr < *(int *)node->content)
	{
		node = node->next;
		pos_b++;
	}
	if (pos <= world->len / 2)
		world->rot.ra = pos;
	if (pos > world->len / 2)
		world->rot.rra = (world->len - pos) + 1;
	if (pos_b <= world->len / 2)
		world->rot.rb = pos - 1;
	if (pos_b > world->len / 2)
		world->rot.rrb = (world->len - pos) + 1;
	get_rot_op(world);
	world->op += 1;
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
		nbr = get_nbr(world, pos);
		if (*(int *)node->content > world->b.max)
			count_max(world, pos);
		if (*(int *)node->content < world->b.min)
			count_min(world, pos);
		else
			count_mid(world, pos, nbr);
		pos++;
		if (!world->min_op)
		{
			world->min_op = world->op;
			world->pos_min_op = pos;
		}
		if (world->op < world->min_op)
		{
			world->min_op = world->op;
			world->pos_min_op = pos;
		}
		node = node->next;
	}
}
