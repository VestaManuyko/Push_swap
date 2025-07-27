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

void	sort_list(t_world *world)
{
	size_t	len;

	len = ft_lstsize(*world->stack_a);
	if (len == 2)
	{
		rotate_a(world);
		return ;
	}
	if (len == 3)
		sort_3(world);
}
