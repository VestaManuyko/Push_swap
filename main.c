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

void	print_list(t_world *world)
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
void	printf_list_2(t_world *world)
{
	t_list	*node;

	if (!world->stack_b || !*world->stack_b)
		return ;
	node = *world->stack_b;
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
	world->pos_b.max = 1;
	world->pos_b.min = 1;
	world->b.max = 0;
	world->b.min = 0;
	world->op = 0;
	world->pos_min_op = 0;
	world->min_op = -1;
	world->rot.ra = 0;
	world->rot.rb = 0;
	world->rot.rra = 0;
	world->rot.rrb = 0;
	world->b_len = 0;
	world->a_len = 0;
	create_stacks(world);
}

int	sorted(t_world *world)
{
	t_list	*node;

	node = *(world->stack_a);
	while (node->next)
	{
		if (*(int *)node->content > *(int *)node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	size_t	i;
	t_world	world;

	world_init(&world);
	i = 1;
	if (argc < 2)
		return (0);
	else
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
	if (sorted(&world))
		return (0);
	sort_list(&world);
	//print_list(&world);
	clean_up(&world, EXIT_SUCCESS);
}
