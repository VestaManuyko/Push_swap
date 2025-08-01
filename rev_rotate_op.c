/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:05:18 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/22 17:05:22 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_world *world)
{
	t_list	*new_last;

	if (!(*world->stack_a))
		return ;
	new_last = (*world->stack_a)->next;
	while (new_last)
	{
		if (!(*new_last->next).next)
			break ;
		new_last = new_last->next;
	}
	ft_lstadd_front(world->stack_a, ft_lstlast((*world->stack_a)));
	new_last->next = NULL;
	ft_printf("rra\n");
}

void	rev_rotate_b(t_world *world)
{
	t_list	*new_last;

	if (!(*world->stack_b))
		return ;
	new_last = (*world->stack_b)->next;
	while (new_last)
	{
		if (!(*new_last->next).next)
			break ;
		new_last = new_last->next;
	}
	ft_lstadd_front(world->stack_b, ft_lstlast((*world->stack_b)));
	new_last->next = NULL;
	ft_printf("rrb\n");
}

void	rev_rotate_all(t_world *world)
{
	rev_rotate_a(world);
	rev_rotate_b(world);
	ft_printf("rrr\n");
}
