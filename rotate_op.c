/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:16:51 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/11 14:16:52 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_world *world)
{
	t_list	*temp;
	t_list	*new_head;

	if (!*world->stack_a || !(*world->stack_a)->next)
		return ;
	temp = *world->stack_a;
	new_head = temp->next;
	temp->next = NULL;
	*world->stack_a = new_head;
	ft_lstadd_back(world->stack_a, temp);
	ft_printf("ra\n");
}

void	rotate_b(t_world *world)
{
	t_list	*temp;
	t_list	*new_head;

	if (!(*world->stack_b) || !(*world->stack_b)->next)
		return ;
	temp = *world->stack_b;
	new_head = temp->next;
	temp->next = NULL;
	*world->stack_b = new_head;
	ft_lstadd_back(world->stack_b, temp);
	ft_printf("rb\n");
}

void	rotate_all(t_world *world)
{
	t_list	*temp;
	t_list	*new_head;
	t_list	*temp2;
	t_list	*new_head2;

	if (!(*world->stack_b) || !(*world->stack_b)->next
		|| !*world->stack_a || !(*world->stack_a)->next)
		return ;
	temp = *world->stack_b;
	new_head = temp->next;
	temp->next = NULL;
	*world->stack_b = new_head;
	ft_lstadd_back(world->stack_b, temp);
	temp2 = *world->stack_a;
	new_head2 = temp2->next;
	temp2->next = NULL;
	*world->stack_a = new_head2;
	ft_lstadd_back(world->stack_a, temp2);
	ft_printf("rr\n");
}
