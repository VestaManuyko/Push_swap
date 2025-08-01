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

static void	min_4_2(t_world *world, int pos_min)
{
	if (pos_min == 2)
		rotate_a(world);
	if (pos_min == 3)
	{
		rev_rotate_a(world);
		rev_rotate_a(world);
	}
	if (pos_min == 4)
		rev_rotate_a(world);
	push_to_b(world);
}

void	min_4(t_world *world)
{
	t_list	*node;
	int		pos;
	int		min;
	int		i;
	int		pos_min;

	i = 0;
	pos = 1;
	node = *world->stack_a;
	if (*(int *)node->content)
		min = *(int *)node->content;
	while (node)
	{
		if (min > *(int *)node->content)
		{
			min = *(int *)node->content;
			pos_min = pos;
		}
		node = node->next;
		pos++;
	}
	min_4_2(world, pos_min);
}
