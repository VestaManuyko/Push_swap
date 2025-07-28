/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:21:17 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/27 14:21:18 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_world *world)
{
	t_list	*node;

	node = *world->stack_a;
	if (!node->next)
		return ;
	if (*(int *)node->content > *(int *)node->next->content)
	{
		swap_a(world);
		node = node->next;
		if (*(int *)node->content > *(int *)node->next->content)
			swap_a(world);
	}
	else
	{
		rev_rotate_a(world);
		swap_a(world);
	}
}

void	find_minmax(t_world *world)
{
	t_list	*node;
	int 	pos;

	pos = 0;
	node = *world->stack_a;
	if (*(int *)node->content)
		world->min = *(int *)node->content;
	while (node)
	{
		if (world->min > *(int *)node->content)
		{
			world->min = *(int *)node->content;
			world->pos_min = pos;
		}
		if (world->min == *(int *)node->content)
			world->pos_min = pos;
		if (world->max == *(int *)node->content)
			world->pos_max = pos;
		if (world->max < *(int *)node->content)
		{
			world->max = *(int *)node->content;
			world->pos_max = pos;
		}
		node= node->next;
		pos++;
	}
}

static int	empty_stack(t_world *world, char stack)
{
	t_list	*node;

	if (stack == 'A')
	{
		node = *world->stack_a;
		if (((node->next)->next)->next == NULL)
			return (0);
		return (1);
	}
	if (stack == 'B')
	{
		node = *world->stack_b;
		if (node == NULL)
			return (0);
		return (1);
	}
	return (0);
}

void	sort_big(t_world *world)
{
	while (empty_stack(world, 'A'))
	{
		find_minmax(world);
		if (world->pos_min == 0)
			push_to_b(world);
		else
		{
			if (world->pos_min > world->len/2)
				rev_rotate_a(world);
			else
				rotate_a(world);
		}
	}
	if (!check_sort(world))
		sort_3(world);
	while (empty_stack(world, 'B'))
		push_to_a(world);
}

void	sort_list(t_world *world)
{
	world->len = ft_lstsize(*world->stack_a);
	if (world->len == 2)
	{
		rotate_a(world);
		return ;
	}
	if (world->len == 3)
		sort_3(world);
	else
		sort_big(world);
}
