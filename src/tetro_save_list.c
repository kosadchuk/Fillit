/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro_save_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:00:01 by kosadchu          #+#    #+#             */
/*   Updated: 2019/02/13 21:35:29 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*cut_str(char *str, int *i)
{
	int			j;
	char		*buf;
	char		*t;

	j = 0;
	buf = ft_memalloc(22);
	while (j < 21)
		buf[j++] = str[(*i)++];
	buf[j] = '\0';
	t = buf;
	free(buf);
	return (t);
}

t_tetro			*save_tetro(char *str, char letter)
{
	int			i;
	int			xx;
	int			yy;
	t_tetro		*lst;

	lst = ft_memalloc(sizeof(t_tetro));
	lst->abc = letter;
	i = -1;
	xx = 0;
	yy = 0;
	while (str[++i])
		if (str[i] == '#')
		{
			lst->x[xx++] = i % 5;
			lst->y[yy++] = i / 5;
		}
	width_height(&lst);
	return (lst);
}

int				save_string(t_tetro **head, char *str)
{
	int			i;
	int			count;
	char		letter;
	t_tetro		*tmp;
	const int	len = ft_strlen(str);

	i = 0;
	count = 0;
	letter = 'A';
	while (i < len)
	{
		tmp = (letter == 'A') ?
		(*head = save_tetro(cut_str(str, &i), letter++)) :
		(tmp->next = save_tetro(cut_str(str, &i), letter++));
		count++;
	}
	return (count);
}
