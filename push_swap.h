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

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>

typedef struct s_world
{
	t_list	**lst;
	char	**split;
}	t_world;

//free.c
void	free_split(t_world *world);
void	clean_up(t_world *world, int status);
//helpers.c
void	valid_nbr(char *split, t_world *world);
void	error_message(const char *s, t_world *world);
int		ft_atoi(const char *nptr, t_world *world);

#endif