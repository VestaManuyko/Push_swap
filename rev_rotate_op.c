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
	t_list	*last;
	t_list	*second_tolast;

	second_tolast = NULL;
	last = *world->stack_a;
	if (!last || !last->next)
		return ;
	while (last->next)
	{
		second_tolast = last;
		last = last->next;
	}
	second_tolast->next = NULL;
	last->next = *world->stack_a;
	*world->stack_a = last;
	ft_printf("rra\n");
}

void	rev_rotate_b(t_world *world)
{
	t_list	*last;
	t_list	*second_tolast;

	second_tolast = NULL;
	last = *world->stack_b;
	if (!last || !last->next)
		return ;
	while (last->next)
	{
		second_tolast = last;
		last = last->next;
	}
	second_tolast->next = NULL;
	last->next = *world->stack_b;
	*world->stack_b = last;
	ft_printf("rrb\n");
}

static void	rev_rotate_b2(t_world *world)
{
	t_list	*last;
	t_list	*second_tolast;

	second_tolast = NULL;
	last = *world->stack_b;
	if (!last || !last->next)
		return ;
	while (last->next)
	{
		second_tolast = last;
		last = last->next;
	}
	second_tolast->next = NULL;
	last->next = *world->stack_b;
	*world->stack_b = last;
}

void	rev_rotate_all(t_world *world)
{
	t_list	*last;
	t_list	*second_tolast;

	second_tolast = NULL;
	last = *world->stack_a;
	if (!last || !last->next)
		return ;
	while (last->next)
	{
		second_tolast = last;
		last = last->next;
	}
	second_tolast->next = NULL;
	last->next = *world->stack_a;
	*world->stack_a = last;
	rev_rotate_b2(world);
	ft_printf("rrr\n");
}
