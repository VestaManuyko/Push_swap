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

static void	lst_create(t_world *world, char *argv)
{
	int	*nbr;
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

static void world_init(t_world *world)
{
	t_list	*head;

	head = NULL;
	world->split = NULL;
	world->lst = &head;
}

int	main(int argc, char **argv)
{
	size_t	i;
	size_t	j;
	t_world	world;

	i = 1;
	j = 0;
	world_init(&world);
	if (argc < 1)
		error_message("Wrong input, needed more arguments", &world);
	else if (argc > 1)
	{
		while (argv[i])
		{
			if (argv[i][j])
			{
				if (argv[i][j] == ' ')
					lst_create(&world, argv[i]);
				j++;
			}
			lst_create(&world, argv[i]);
			i++;
		}
	}
	print_list(&world);
	clean_up(&world, EXIT_SUCCESS);
}
