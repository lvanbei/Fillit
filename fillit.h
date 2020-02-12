/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 09:09:50 by bruno             #+#    #+#             */
/*   Updated: 2018/12/20 13:05:21 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# define TETRI_SIZE 4

# define ERROR_USAGE	1
# define ERROR_MALLOC	2
# define ERROR_CHECK	3
# define ERROR_FREE		4
# define ERROR_OPEN		5
# define ERROR_CLOSE	6

typedef	enum	e_bool
{
	false,
	true
}				t_bool;

typedef	struct	s_tetri
{
	char				name;
	char				*tetri;
	struct s_tetri		*next;
}				t_tetri;

typedef	struct	s_map
{
	int			x;
	int			y;
	char		empty_token;
	char		full_token;
	char		*map;
}				t_map;

typedef struct	s_game
{
	t_tetri		*list;
	t_map		*grid;
}				t_game;

typedef struct	s_cord
{
	int x;
	int y;
	int block_x;
	int block_y;
}				t_cord;

/*
	**Main.c
*/

void			delete_game(t_game *game);

void			init_game(t_game *game, char *file);

/*
	**Read.c
*/

int				get_nbr_tetri(char *file, t_game *game);

char			*get_tetri(int fd);

t_tetri			*read_file(char *file, t_game *game);

/*
	**Tetriminos.c
*/

t_tetri			*new_tetri();

void			set_tetri(t_tetri *lst, char *line);

t_tetri			*init_list(int nbr);

void			delete_list(t_tetri *list);

/*
	**Print.c
*/

t_bool			print_error(int	error, t_game *game);

t_bool			print_usage(void);

void			print_map(t_map *grid);

/*
	**Map.c
*/

t_map			*init_map(char *file, t_game *game);

void			set_map(t_map *grid, int x, int y);

char			*create_empty_map(int x, int y);

void			set_token(t_map *grid, int x, int y, char token);

void			delete_map(t_map *grid);

/*
	**Solve.c
*/

void			set_map_tetri(t_map *grid,
	t_tetri *list, t_cord *xy, char token);

t_bool			map_check_tetri(t_map *grid, t_tetri *list, t_cord *xy);

t_bool			map_check_tetri_2(t_map *grid, t_tetri *list, t_cord *xy);

t_bool			backtracking(t_tetri *list, t_map *grid, t_game *game);

void			solve(t_game *game);

/*
	**Solve_2.c
*/

t_bool			backtracking_2(t_cord *xy, t_map *grid);

t_bool			ft_free_troll(t_cord *xy);
/*
	**Valid_file.c
*/

t_bool			check_length(t_tetri *list);

t_bool			check_token(t_tetri *list);

int				nbr_touch(t_tetri *list, int i, int j);

t_bool			check_if_tetri(t_tetri *list);

t_bool			check_all(t_tetri *list);

#endif
