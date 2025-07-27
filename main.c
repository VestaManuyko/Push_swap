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

static void	print_list(t_world *world)
{
	t_list	*node;

	if (!world->stack_a || !*world->stack_a)
		return ;
	node = *world->stack_a;
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

static void	create_stacks(t_world *world)
{
	world->stack_a = malloc(sizeof(t_list *));
	if (!world->stack_a)
		error_message("Malloc for stack_a failed", world);
	*(world->stack_a) = NULL;
	world->stack_b = malloc(sizeof(t_list *));
	if (!world->stack_b)
		error_message("Malloc for stack_b failed", world);
	*(world->stack_b) = NULL;
}

static void	world_init(t_world *world)
{
	world->split = NULL;
	world->stack_a = NULL;
	world->stack_b = NULL;
	create_stacks(world);
}

int	check_sort(t_world *world)
{
	t_list	*node;

	node = *(world->stack_a);
	while (node->next)
	{
		if (*(int *)node->content > *(int *)node->next->content)
			return (1);
		node = node->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	size_t	i;
	t_world	world;

	world_init(&world);
	i = 1;
	if (argc <= 1)
		return (0);
	if (argc == 2)
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
	check_dup((*world.stack_a), &world);
	if (!check_sort(&world))
		return (0);
	//sort list if needed
	print_list(&world);
	clean_up(&world, EXIT_SUCCESS);
}
