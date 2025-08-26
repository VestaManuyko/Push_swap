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

static void	valid_nbr(char *number, t_world *world)
{
	size_t	i;

	i = 0;
	while (number[i])
	{
		if (!ft_isdigit(number[i]) && number[i] != '-')
			error_message("Incorrect input\n", world);
		i++;
	}
}

void	int_lst_create(t_world *world, char *argv)
{
	int		*nbr;
	t_list	*node;

	valid_nbr(argv, world);
	nbr = malloc(sizeof(int));
	if (!nbr)
		error_message("Malloc of nbr failed\n", world);
	world->check = ft_atoi_new(argv);
	if (world->check == ATOI_ERROR)
	{
		free(nbr);
		error_message("Number not in int range\n", world);
	}
	*nbr = (int)world->check;
	node = ft_lstnew(nbr);
	if (!node)
	{
		free(nbr);
		error_message("Malloc failed on node creation", world);
	}
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
		error_message("Malloc failed on split\n", world);
	while (world->split[i])
	{
		valid_nbr(world->split[i], world);
		nbr = malloc(sizeof(int));
		if (!nbr)
			error_message("Malloc of nbr failed\n", world);
		world->check = ft_atoi_new(world->split[i++]);
		if (world->check == ATOI_ERROR)
			return (free(nbr), error_message("Nbr not in int range\n", world));
		*nbr = (int)world->check;
		node = ft_lstnew(nbr);
		if (!node)
			return (free(nbr), error_message("Malloc node failed\n", world));
		ft_lstadd_back(world->stack_a, node);
	}
}
