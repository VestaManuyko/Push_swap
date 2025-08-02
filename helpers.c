/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:06:26 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/09 15:06:27 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(const char *s, t_world *world)
{
	write (2, "Error\n", 6);
	write (2, s, ft_strlen(s));
	clean_up(world, EXIT_FAILURE);
}

int	get_nbr(t_world *world, int pos)
{
	t_list	*node;
	int		i;
	int		nbr;

	i = 0;
	node = (*world->stack_a);
	while (node && i < pos)
	{
		i++;
		nbr = *(int *)node->content;
		node = node->next;
	}
	return (nbr);
}

void	valid_nbr(char *number, t_world *world)
{
	size_t	i;

	i = 0;
	while (number[i])
	{
		if (!ft_isdigit(number[i]) && number[i] != '-')
			error_message("Number contains not only digits", world);
		i++;
	}
}

static long	atoi_2(int sign, long number)
{
	if ((sign == 1 && number > INT_MAX)
		|| (sign == -1 && (-number) < INT_MIN))
		return (ATOI_ERROR_2);
	return (0);
}

long	ft_atoi_new(const char *nptr)
{
	int		sign;
	long	number;
	size_t	i;

	i = 0;
	while (nptr[i])
	{
		while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
			i++;
		sign = 1;
		if (nptr[i] == '-' || nptr[i] == '+')
		{
			if (nptr[i] == '-')
				sign *= -1;
			i++;
		}
		if (nptr[i] == '-' || nptr[i] == '+')
			break ;
		number = 0;
		while (ft_isdigit(nptr[i]))
			number = number * 10 + (nptr[i++] - '0');
		if (!atoi_2(sign, number))
			return (sign * (int)number);
	}
	return (ATOI_ERROR);
}
