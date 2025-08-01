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

static void	sort_3(t_world *world)
{
	t_list	*node;

	node = *world->stack_a;
	if (!node->next)
		return ;
	if (!node->next->next && !sorted(world))
		return (rotate_a(world));
	if (*(int *)node->content < *(int *)node->next->content
		&& *(int *)node->content < *(int *)node->next->next->content)
		return (swap_a(world), rotate_a(world));
	if (*(int *)node->content > *(int *)node->next->content)
	{
		if (*(int *)node->next->content > *(int *)node->next->next->content)
			return (rotate_a(world), swap_a(world));
		if (*(int *)node->next->content < *(int *)node->next->next->content)
		{
			if (*(int *)node->content > *(int *)node->next->next->content)
				return (rotate_a(world));
			else
				return (swap_a(world));
		}
	}
	else
		rev_rotate_a(world);
}

static int	empty_stack(t_world *world, char stack)
{
	t_list	*node;

	if (stack == 'A')
	{
		node = *world->stack_a;
		if (!node)
			return (1);
		return (0);
	}
	if (stack == 'B')
	{
		node = *world->stack_b;
		if (!node)
			return (1);
		return (0);
	}
	return (0);
}

static void	sort_big(t_world *world)
{
	push_to_b(world);
	push_to_b(world);
	while (!empty_stack(world, 'A'))
	{
		find_minmax(world);
		find_cheap(world);
	}
	while (!empty_stack(world, 'B'))
		push_to_a(world);
}

void	sort_list(t_world *world)
{
	t_list	*node;

	node = *world->stack_a;
	world->len = ft_lstsize(*world->stack_a);
	if (world->len == 2)
	{
		rotate_a(world);
		return ;
	}
	if (world->len == 3)
		sort_3(world);
	if (world->len == 4)
	{
		min_4(world);
		sort_3(world);
		push_to_a(world);
	}
	else
		sort_big(world);
}
