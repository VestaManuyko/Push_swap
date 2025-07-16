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
}

void	clean_up(t_world *world, int status)
{
	free_split(world);
	free_list(world->stack_a);
	// FIX add smth like this, but debug free_list(world->stack_b);
	if (status == EXIT_FAILURE)
		exit(1);
	if (status == EXIT_SUCCESS)
		exit(0);
}
