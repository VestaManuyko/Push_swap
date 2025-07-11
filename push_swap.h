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
#define ATOI_ERROR_2 4444444444

typedef struct s_world
{
	t_list	**lst;
	char	**split;
}	t_world;

//free.c
void	free_split(t_world *world);
void	clean_up(t_world *world, int status);
//helpers.c
void	valid_nbr(char *number, t_world *world);
void	error_message(const char *s, t_world *world);
long	ft_atoi(const char *nptr);

#endif