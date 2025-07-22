/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:16:57 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/11 14:16:58 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_world *world)
{
	t_list	*temp;

	if (!(*world->stack_a))
		return ;
	temp = *world->stack_a;
	*world->stack_a = (*world->stack_a)->next;
	temp->next = NULL;
	ft_lstadd_front(world->stack_b, temp);
	ft_printf("pb\n");
}

void	push_to_a(t_world *world)
{
	t_list	*temp;

	if (!(*world->stack_b))
		return ;
	temp = *world->stack_b;
	*world->stack_b = (*world->stack_b)->next;
	temp->next = NULL;
	ft_lstadd_front(world->stack_a, temp);
	ft_printf("pa\n");
}
