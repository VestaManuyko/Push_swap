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

static void	free_list(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		if ((*lst)->content)
			free((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

void	clean_up(t_world *world, int status)
{
	free_split(world);
	free_list(world->lst);
	if (status == EXIT_FAILURE)
		exit(1);
	if (status == EXIT_SUCCESS)
		exit(0);
}