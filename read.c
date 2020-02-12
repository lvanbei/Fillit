/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 11:54:57 by bruno             #+#    #+#             */
/*   Updated: 2018/12/10 11:13:21 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_nbr_tetri(char *file, t_game *game)
{
	int		res;
	int		fd;
	char	*line;

	res = 1;
	if (!(fd = open(file, O_RDONLY)))
	{
		print_error(ERROR_OPEN, game);
		return (0);
	}
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strlen(line) == 0 || ft_strlen(line) > 4)
			res++;
		free(line);
	}
	if (close(fd))
		print_error(ERROR_CLOSE, game);
	return (res);
}

char	*get_tetri(int fd)
{
	int		i;
	char	*line;
	char	*tetri;
	char	*tmp;

	i = 0;
	if (!(tetri = ft_strnew(0)))
		return (NULL);
	while (i <= 4 && get_next_line(fd, &line) == 1)
	{
		tmp = tetri;
		if (!(tetri = ft_strjoin(tmp, line)))
			tetri = NULL;
		i++;
		free(line);
		free(tmp);
	}
	return (tetri);
}

t_tetri	*read_file(char *file, t_game *game)
{
	int		tab[2];
	int		count;
	char	*tetri;
	t_tetri	*list;
	t_tetri	*tmp;

	if (!(tab[0] = open(file, O_RDONLY)))
		print_error(ERROR_OPEN, game);
	count = 1;
	tab[1] = get_nbr_tetri(file, game);
	list = init_list(tab[1]);
	tmp = list;
	while (count <= tab[1])
	{
		tetri = get_tetri(tab[0]);
		if (tetri == NULL)
			print_error(ERROR_MALLOC, game);
		set_tetri(tmp, tetri);
		tmp = tmp->next;
		count++;
	}
	if (close(tab[0]))
		print_error(ERROR_CLOSE, game);
	return (list);
}
