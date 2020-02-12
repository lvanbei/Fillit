/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:26:24 by bruno             #+#    #+#             */
/*   Updated: 2018/12/20 13:12:24 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		delete_game(t_game *game)
{
	if (game->list != NULL)
		delete_list(game->list);
	if (game->grid != NULL)
		delete_map(game->grid);
	if (game != NULL)
		free(game);
}

void		init_game(t_game *game, char *file)
{
	if (!(game->list = read_file(file, game)))
		print_error(ERROR_CHECK, game);
	if (!(game->grid = init_map(file, game)))
		print_error(ERROR_CHECK, game);
}

int			main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
		return (print_usage());
	if (!(game = (t_game *)malloc(sizeof(*game))))
		return (0);
	game->list = NULL;
	game->grid = NULL;
	init_game(game, argv[1]);
	if (check_all(game->list))
	{
		solve(game);
		print_map(game->grid);
	}
	else
		return (print_error(ERROR_CHECK, game));
	delete_game(game);
	return (true);
}
