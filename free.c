/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:16:18 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/09 12:16:18 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(t_world *world)
{
	size_t	i;

	i = 0;
	if (!world->split)
		return ;
	while (world->split[i])
	{
		free(world->split[i]);
		world->split[i] = NULL;
		i++;
	}
	free(world->split);
	world->split = NULL;
}

static void	free_list(t_list **list)
{
	t_list	*temp;

	if (!list || !*list)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		if ((*list)->content)
			free((*list)->content);
		free(*list);
		*list = temp;
	}
	*list = NULL;
}

void	clean_up(t_world *world, int status)
{
	free_split(world);
	if (world->stack_a)
	{
		free_list(world->stack_a);
		free(world->stack_a);
		world->stack_a = NULL;
	}
	if (world->stack_b)
	{
		free_list(world->stack_b);
		free(world->stack_b);
		world->stack_b = NULL;
	}
	if (status == EXIT_FAILURE)
		exit(1);
	if (status == EXIT_SUCCESS)
		exit(0);
}
