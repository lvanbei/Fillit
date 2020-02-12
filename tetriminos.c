/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:48:13 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/12/03 14:48:16 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*new_tetri(void)
{
	t_tetri		*new;

	if (!(new = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	else
	{
		if (!(new->tetri = (char *)malloc(sizeof(char) *
		(int)TETRI_SIZE * (int)TETRI_SIZE)))
		{
			free(new);
			return (NULL);
		}
		new->next = NULL;
	}
	return (new);
}

void		set_tetri(t_tetri *lst, char *line)
{
	free(lst->tetri);
	lst->tetri = ft_strdup(line);
	ft_strdel(&line);
}

t_tetri		*init_list(int nbr)
{
	t_tetri		*begin;
	t_tetri		*tmp;
	int			i;

	begin = new_tetri();
	begin->name = 'A';
	tmp = begin;
	i = 0;
	while (i < nbr)
	{
		i++;
		tmp->next = new_tetri();
		tmp = tmp->next;
		tmp->name = 'A' + i;
	}
	return (begin);
}

void		delete_list(t_tetri *list)
{
	t_tetri		*tmp;

	while (list != NULL)
	{
		tmp = list->next;
		free(list->tetri);
		free(list);
		list = tmp;
	}
}
