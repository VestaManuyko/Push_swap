/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:05:38 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/08 15:05:39 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <limits.h>

# define ATOI_ERROR 8888888888
# define ATOI_ERROR_2 4444444444

typedef struct s_world
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	**split;
	int		min;
	int		max;
	int		pos_min;
	int		pos_max;
	int		len;
}	t_world;

//free.c
void	free_split(t_world *world);
void	clean_up(t_world *world, int status);
//helpers.c
void	valid_nbr(char *number, t_world *world);
void	error_message(const char *s, t_world *world);
long	ft_atoi_new(const char *nptr);
//swap_op.c
void	swap_a(t_world *world); //sa
void	swap_b(t_world *world); //sb
void	swap_all(t_world *world); //ss
//push_op.c
void	push_to_b(t_world *world); //pb
void	push_to_a(t_world *world); //pa
//rotate_op.c
void	rotate_a(t_world *world); //ra
void	rotate_b(t_world *world); //rb
void	rotate_all(t_world *world); //rr
//rev_rotate_op.c
void	rev_rotate_a(t_world *world); //rra
void	rev_rotate_b(t_world *world); //rrb
void	rev_rotate_all(t_world *world); //rrr
//list.c
void	int_lst_create(t_world *world, char *argv);
void	str_lst_create(t_world *world, char *argv);
//sort.c
void	sort_list(t_world *world);
//main.c
int	check_sort(t_world *world);

#endif