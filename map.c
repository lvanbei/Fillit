/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 14:22:41 by cbruno            #+#    #+#             */
/*   Updated: 2018/11/06 12:58:50 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*create_empty_map(int x, int y)
{
	int		i;
	int		j;
	char	*map;

	i = 0;
	if (!(map = (char *)malloc(sizeof(char) * x * y)))
		return (NULL);
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			map[j + i * x] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

t_map	*init_map(char *file, t_game *game)
{
	t_map	*new;
	int		nbr;

	nbr = get_nbr_tetri(file, game);
	if (!(new = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	else
	{
		new->x = ft_sqrt(TETRI_SIZE * nbr);
		new->y = ft_sqrt(TETRI_SIZE * nbr);
		new->empty_token = '.';
		new->full_token = '#';
		new->map = create_empty_map(new->x, new->y);
	}
	return (new);
}

void	set_token(t_map *grid, int x, int y, char token)
{
	grid->map[x + y * grid->y] = token;
}

void	set_map(t_map *grid, int x, int y)
{
	grid->x = x;
	grid->y = y;
	free(grid->map);
	grid->map = create_empty_map(x, y);
}

void	delete_map(t_map *grid)
{
	free(grid->map);
	free(grid);
}
