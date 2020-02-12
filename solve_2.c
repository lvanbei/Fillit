/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:39:38 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/11/29 16:39:40 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_bool		backtracking_2(t_cord *xy, t_map *grid)
{
	xy->x++;
	if (xy->x >= grid->x)
	{
		xy->x = -3;
		xy->y++;
		if (xy->y >= grid->y)
		{
			free(xy);
			return (false);
		}
	}
	return (true);
}

t_bool		ft_free_troll(t_cord *xy)
{
	free(xy);
	return (true);
}
