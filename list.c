/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:25:43 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/25 18:25:44 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	int_lst_create(t_world *world, char *argv)
{
	int		*nbr;
	t_list	*node;
	long	check;

	valid_nbr(argv, world);
	nbr = malloc(sizeof(int));
	if (!nbr)
		error_message("Malloc of nbr failed\n", world);
	check = ft_atoi(argv);
	if (check == ATOI_ERROR || check == ATOI_ERROR_2)
	{
		free(nbr);
		error_message("Incorrect number\n", world);
	}
	*nbr = (int)check;
	node = ft_lstnew(nbr);
	if (!node)
		error_message("Malloc failed on node creation", world);
	ft_lstadd_back(world->stack_a, node);
}

void	str_lst_create(t_world *world, char *argv)
{
	int		*nbr;
	size_t	i;
	t_list	*node;

	i = 0;
	if (world->split)
		free_split(world);
	world->split = ft_split(argv, ' ');
	if (!world->split)
		error_message("Malloc failed on split", world);
	while (world->split[i])
	{
		valid_nbr(world->split[i], world);
		nbr = malloc(sizeof(int));
		if (!nbr)
			error_message("Malloc of nbr failed\n", world);
		*nbr = ft_atoi(world->split[i]);
		node = ft_lstnew(nbr);
		if (!node)
			error_message("Malloc failed on node creation", world);
		ft_lstadd_back(world->stack_a, node);
		i++;
	}
}
