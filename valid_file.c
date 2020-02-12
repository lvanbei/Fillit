/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 09:39:39 by cbruno            #+#    #+#             */
/*   Updated: 2018/11/29 17:11:58 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_bool			check_length(t_tetri *list)
{
	while (list->next != NULL)
	{
		if (ft_strlen(list->tetri) != TETRI_SIZE * TETRI_SIZE)
			return (false);
		list = list->next;
	}
	return (true);
}

t_bool			check_token(t_tetri *list)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < TETRI_SIZE)
	{
		j = 0;
		while (j < TETRI_SIZE)
		{
			if (list->tetri[j + i * TETRI_SIZE] != '.')
				if (list->tetri[j + i * TETRI_SIZE] != '#')
					return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int				nbr_touch(t_tetri *list, int i, int j)
{
	int		count_touch;

	count_touch = 0;
	if (j + 1 < TETRI_SIZE)
		if (list->tetri[(j + 1) + i * TETRI_SIZE] == '#')
			count_touch++;
	if (j - 1 >= 0)
		if (list->tetri[(j - 1) + i * TETRI_SIZE] == '#')
			count_touch++;
	if (i + 1 < TETRI_SIZE)
		if (list->tetri[j + (i + 1) * TETRI_SIZE] == '#')
			count_touch++;
	if (i - 1 >= 0)
		if (list->tetri[j + (i - 1) * TETRI_SIZE] == '#')
			count_touch++;
	return (count_touch);
}

t_bool			check_if_tetri(t_tetri *list)
{
	int		i;
	int		j;
	int		count_nbr;
	int		count_touch;

	count_nbr = 0;
	count_touch = 0;
	i = 0;
	while (i < TETRI_SIZE)
	{
		j = 0;
		while (j < TETRI_SIZE)
		{
			if (list->tetri[j + i * TETRI_SIZE] == '#')
			{
				count_nbr++;
				count_touch += nbr_touch(list, i, j);
			}
			j++;
		}
		i++;
	}
	return ((count_touch >= 6 && count_nbr == 4) ? true : false);
}

t_bool			check_all(t_tetri *list)
{
	int		count;

	count = 0;
	if (!check_length(list))
		return (false);
	while (list->next != NULL)
	{
		count++;
		if (count > 26)
			return (false);
		if (!(check_if_tetri(list) && check_token(list)))
			return (false);
		list = list->next;
	}
	return (true);
}
