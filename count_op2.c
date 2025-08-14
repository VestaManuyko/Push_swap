/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 02:34:15 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/08/14 02:34:16 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_rot_op(t_world *world)
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

int	get_pos_b(t_world *world, int nbr)
{
	t_list	*node;
	int		next;
	int		pos_b;

	pos_b = 1;
	node = *world->stack_b;
	while (node)
	{
		if (!node->next)
			break ;
		next = *(int *)(node->next)->content;
		if (nbr < *(int *)node->content && nbr > next)
			return (pos_b + 1);
		node = node->next;
		pos_b++;
	}
	next = *(int *)(*world->stack_b)->content;
	if (nbr < *(int *)node->content && nbr > next)
		return (pos_b + 1);
	return (pos_b);
}
