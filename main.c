/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:25:29 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/08 14:25:30 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	str_lst_create(t_world *world, char *argv)
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
		*nbr = ft_atoi(world->split[i], world);
		node = ft_lstnew(nbr);
		if (!node)
			error_message("Malloc failed on node creation", world);
		ft_lstadd_back(world->lst, node);
		i++;
	}
}

static void	int_lst_create(t_world *world, char *argv)
{
	int		*nbr;
	t_list	*node;
	long	check;

	valid_nbr(argv, world);
	nbr = malloc(sizeof(int));
	if (!nbr)
		error_message("Malloc of nbr failed\n", world);
	check = ft_atoi(argv, world);
	if (check == ATOI_ERROR || check == ATOI_ERROR_2)
	{
		free(nbr);
		error_message("Incorrect number\n", world);
	}
	*nbr = (int)check;
	node = ft_lstnew(nbr);
	if (!node)
		error_message("Malloc failed on node creation", world);
	ft_lstadd_back(world->lst, node);
}

static void	print_list(t_world *world)
{
	t_list	*node;

	if (!world->lst || !*world->lst)
		return ;
	node = *world->lst;
	while (node)
	{
		ft_printf("%d\n", *(int *)node->content);
		node = node->next;
	}
}

static void	check_dup(t_list *list, t_world *world)
{
	int		content;
	t_list	*next;

	if (!list)
		return ;
	content = *(int *)list->content;
	next = list->next;
	while (next)
	{
		if (content == *(int *)next->content)
			error_message("Duplicate found", world);
		next = next->next;
	}
	check_dup(list->next, world);
}

int	main(int argc, char **argv)
{
	size_t	i;
	t_world	world;
	t_list	*head;

	head = NULL;
	world.split = NULL;
	world.lst = &head;
	i = 1;
	if (argc < 1)
		error_message("Wrong input, needed more arguments", &world);
	else if (argc > 1)
	{
		while (argv[i])
		{
			if (ft_strchr(argv[i], ' '))
				str_lst_create(&world, argv[i]);
			else
				int_lst_create(&world, argv[i]);
			i++;
		}
	}
	check_dup(head, &world);
	print_list(&world);
	clean_up(&world, EXIT_SUCCESS);
}
