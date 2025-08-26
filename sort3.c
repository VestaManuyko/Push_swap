/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 19:42:32 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/08/02 19:42:33 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_4_2(t_world *world, int pos_min)
{
	if (pos_min == 2)
		rotate_a(world);
	if (pos_min == 3)
	{
		rotate_a(world);
		rotate_a(world);
	}
	if (pos_min == 4 && world->a_len == 4)
		rev_rotate_a(world);
	if (pos_min == 4 && world->a_len == 5)
	{
		rev_rotate_a(world);
		rev_rotate_a(world);
	}
	if (pos_min == 5)
		rev_rotate_a(world);
	if (!sorted(world, 'A'))
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
	min = 0;
	pos_min = 0;
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

void	sort_5(t_world *world)
{
	min_4(world);
	world->a_len = ft_lstsize(*world->stack_a);
	min_4(world);
	if (!sorted(world, 'A'))
		sort_3(world);
	if (!empty_stack(world, 'B'))
	{
		if (sorted(world, 'B'))
			rotate_b(world);
	}
	while (!empty_stack(world, 'B'))
		push_to_a(world);
}
