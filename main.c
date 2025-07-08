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

void	error_message(const char *s)
{
	write (2, "Error\n", 6);
	write (2, s, ft_strlen(s));
	//FIX consider exiting with error, smth like clean_up(EXIT_FAIL)
}

int	main(void)
{
	error_message("Malloc failed");
}