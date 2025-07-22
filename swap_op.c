/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:17:05 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/11 14:17:06 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_world *world)
{
	int	*temp;

	if (!(*world->stack_a) || !(*world->stack_a)->next)
		return ;
	temp = (int *)(*world->stack_a)->content;
	(*world->stack_a)->content = (*(*world->stack_a)->next).content;
	(*(*world->stack_a)->next).content = temp;
}

void	swap_b(t_world *world)
{
	int	*temp;

	if (!(*world->stack_b) || !(*world->stack_b)->next)
		return ;
	temp = (int *)(*world->stack_b)->content;
	(*world->stack_b)->content = (*(*world->stack_b)->next).content;
	(*(*world->stack_b)->next).content = temp;
}

void	swap_all(t_world *world)
{
	swap_a(world);
	swap_b(world);
}
