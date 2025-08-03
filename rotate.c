/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:33:59 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/08/03 18:34:00 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rev_rotate(t_world *world)
{
	int	i;

	i = 0;
	if (world->rot.rra >= world->rot.rrb)
	{
		while (world->rot.rrb && i++ < world->rot.rrb)
			rev_rotate_all(world);
		while (i++ < world->rot.rra)
			rev_rotate_a(world);
	}
	if (world->rot.rrb > world->rot.rra)
	{
		i = 0;
		while (i < world->rot.rra)
		{
			rev_rotate_all(world);
			i++;
		}
		while (i++ < world->rot.rrb)
			rev_rotate_b(world);
	}
}

void	do_rotate(t_world *world)
{
	int	i;

	i = 0;
	if (world->rot.ra >= world->rot.rb)
	{
		while (world->rot.rb && i++ < world->rot.rb)
			rotate_all(world);
		while (i++ < world->rot.ra)
			rotate_a(world);
	}
	if (world->rot.rb > world->rot.ra)
	{
		i = 0;
		while (i < world->rot.ra)
		{
			rotate_all(world);
			i++;
		}
		while (i++ < world->rot.rb)
			rotate_b(world);
	}
	do_rev_rotate(world);
}
