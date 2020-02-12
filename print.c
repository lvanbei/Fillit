/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:26:40 by bruno             #+#    #+#             */
/*   Updated: 2018/12/20 13:08:18 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_bool	print_error(int error, t_game *game)
{
	if (error == ERROR_USAGE)
		ft_putendl("usage: ./fillit <datafile>");
	else
		ft_putendl("error");
	delete_game(game);
	exit(1);
	return (false);
}

t_bool	print_usage(void)
{
	ft_putendl("usage: ./fillit <datafile>");
	return (false);
}

void	print_map(t_map *grid)
{
	int		i;
	int		j;

	i = 0;
	while (i < grid->x)
	{
		j = 0;
		while (j < grid->y)
		{
			ft_putchar((grid->map)[j + i * (grid->x)]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
