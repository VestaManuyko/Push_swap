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
	exit(EXIT_FAILURE);
	//FIX consider exiting with error, smth like clean_up(EXIT_FAIL)
}

int	check_list(t_list **lst)
{
	(void)lst;
	return (0);
}

int	main(int argc, char **argv)
{
	size_t	i;
	size_t	j;
	size_t	r;
	t_list	**lst;
	char	**split;
	int		nbr;

	i = 1;
	j = 0;
	r = 0;
	split = NULL;
	lst = NULL;
	if (argc < 1)
		error_message("Wrong input, needed more arguments");
	else if (argc > 1)
	{
		while (argv[i])
		{
			while (argv[i][j])
			{
				if (argv[i][j] == ' ')
				{
					split = ft_split(argv[i], ' ');
					while (split[r])
					{
						nbr = ft_atoi(split[r]);
						//FIX test for int_min int_max
						if (nbr == -1)
							error_message("Wrong input, incorrect number");
						r++;
					}
					ft_lstadd_back(lst, ft_lstnew(&nbr));
				}
				j++;
			}
			i++;
		}
		check_list(lst);
	}
	//FIX later you need to free all trimmed strings used here
	return (0);
}