/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:33:37 by cbruno            #+#    #+#             */
/*   Updated: 2018/12/07 13:07:58 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_map_tetri(t_map *grid, t_tetri *list, t_cord *xy, char token)
{
	int		block_x;
	int		block_y;

	block_y = 0;
	while (block_y < TETRI_SIZE)
	{
		block_x = 0;
		while (block_x < TETRI_SIZE)
		{
			if (list->tetri[block_x + block_y * TETRI_SIZE] == grid->full_token)
			{
				set_token(grid, xy->x + block_x, xy->y + block_y, token);
			}
			block_x++;
		}
		block_y++;
	}
}

t_bool	map_check_tetri_2(t_map *grid, t_tetri *list, t_cord *xy)
{
	if (list->tetri[xy->block_x + xy->block_y * TETRI_SIZE]
		== (grid)->full_token)
	{
		if (((xy->x + xy->block_x) >= 0 && (xy->x + xy->block_x) < grid->x)
				&& ((xy->y + xy->block_y) >= 0 &&
					(xy->y + xy->block_y) < grid->y))
		{
			if ((grid)->map[xy->x + xy->block_x +
				(xy->y + xy->block_y) * (grid)->y]
				!= (grid)->empty_token)
				return (false);
		}
		else
			return (false);
	}
	return (true);
}

t_bool	map_check_tetri(t_map *grid, t_tetri *list, t_cord *xy)
{
	xy->block_y = 0;
	while (xy->block_y < TETRI_SIZE)
	{
		xy->block_x = 0;
		while (xy->block_x < TETRI_SIZE)
		{
			if (!(map_check_tetri_2(grid, list, xy)))
				return (false);
			xy->block_x++;
		}
		xy->block_y++;
	}
	return (true);
}

t_bool	backtracking(t_tetri *list, t_map *grid, t_game *game)
{
	t_cord	*xy;
	t_bool	is_solution;

	if (!(xy = (t_cord*)malloc(sizeof(t_cord))))
		return (print_error(ERROR_MALLOC, game));
	if (list == NULL)
		return (ft_free_troll(xy));
	xy->x = -4;
	xy->y = -3;
	is_solution = false;
	while (!is_solution)
	{
		if (!(backtracking_2(xy, grid)))
			return (false);
		if (map_check_tetri(grid, list, xy) == true)
		{
			set_map_tetri(grid, list, xy, list->name);
			if (is_solution)
				free(xy);
			is_solution = backtracking(list->next, grid, game);
			if (!is_solution)
				set_map_tetri(grid, list, xy, grid->empty_token);
		}
	}
	return (ft_free_troll(xy));
}

void	solve(t_game *game)
{
	while (backtracking(game->list, game->grid, game) == false)
	{
		set_map((game->grid), (game->grid)->x + 1, (game->grid)->y + 1);
	}
}
