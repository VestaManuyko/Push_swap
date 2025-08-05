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
	if (!world->do_all)
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
	if (!world->do_all)
		ft_printf("rb\n");
}

void	rotate_all(t_world *world)
{
	world->do_all = 1;
	rotate_a(world);
	rotate_b(world);
	ft_printf("rr\n");
}
