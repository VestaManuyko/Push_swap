/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:03:32 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/29 15:03:33 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_max(t_world *world)
{
	t_list	*node;
	int		pos;

	pos = 0;
	node = *world->stack_b;
	if (*(int *)node->content)
		world->b.max = *(int *)node->content;
	while (node)
	{
		if (world->b.max < *(int *)node->content)
		{
			world->b.max = *(int *)node->content;
			world->pos_b.max = pos;
		}
		if (world->b.max == *(int *)node->content)
			world->pos_b.max = pos;
		node = node->next;
		pos++;
	}
}

static void	find_min(t_world *world)
{
	t_list	*node;
	int		pos;

	pos = 0;
	node = *world->stack_b;
	if (*(int *)node->content)
		world->b.min = *(int *)node->content;
	while (node)
	{
		if (world->b.min > *(int *)node->content)
		{
			world->b.min = *(int *)node->content;
			world->pos_b.min = pos;
		}
		if (world->b.min == *(int *)node->content)
			world->pos_b.min = pos;
		node = node->next;
		pos++;
	}
}

void	find_minmax(t_world *world)
{
	find_min(world);
	find_max(world);
}
