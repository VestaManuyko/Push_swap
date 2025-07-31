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

static void	count_max(t_world *world, int pos)
{
	int	ra;
	int	rra;
	int	op;

	op = 0;
	ra = 0;
	rra = 0;
	if (pos <= world->len/2)
		ra = pos - 1;
	else
		rra = (world->len - pos) + 1;
	if (world->pos_b.max != 1 && rra != 0)
		op = rra + 1;
	if (world->pos_b.max != 1 && ra != 0)
		op = ra + 2;
	if (!world->op)
		world->op = op;
	if (op < world->op)
	{
		world->op = op;
		world->pos_min_op = pos;
	}
}

static void	count_min(t_world *world, int pos)
{
	int	ra;
	int	rra;
	int	op;

	op = 0;
	ra = 0;
	rra = 0;
	if (pos <= world->len/2)
		ra = pos;
	else
		rra = (world->len - pos) + 1;
	if (rra != 0)
		op = rra + 2;
	if (!world->op)
		world->op = op;
	if (op < world->op)
	{
		world->op = op;
		world->pos_min_op = pos;
	}
}

// static void	count_mid(t_world *world, int pos)
// {

// }

void	cheap_sort(t_world *world)
{
	t_list	*node;
	int		pos;

	pos = 1;
	node = *world->stack_a;
	while (node)
	{
		if (*(int *)(*world->stack_a)->content > world->b.max)
			count_max(world, pos);
		if (*(int *)(*world->stack_a)->content < world->b.min)
			count_min(world, pos);
		// else
		// 	count_mid(world, pos);
		pos++;
		node = node->next;
	}
	ft_printf("Min nbr of ops needed for this list %d and the pos of element %d\n", world->op, world->pos_min_op);
}
