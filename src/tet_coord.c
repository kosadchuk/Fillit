/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:10:47 by kosadchu          #+#    #+#             */
/*   Updated: 2019/02/13 21:36:58 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			min_max(t_mn_mx **m)
{
	t_mn_mx		*tmp;

	tmp = ft_memalloc(sizeof(t_mn_mx));
	tmp->maxx = 0;
	tmp->maxy = 0;
	tmp->minx = 3;
	tmp->miny = 3;
	(*m) = tmp;
}

void			change_coord(int min, int *arr)
{
	int			i;

	i = -1;
	if (min > 0)
		while (++i < 4)
			arr[i] -= min;
}

t_tetro			*width_height(t_tetro **tet)
{
	t_mn_mx		*m;
	int			i;

	i = -1;
	min_max(&m);
	while (++i < 4)
	{
		((*tet)->x[i] < m->minx) ? (m->minx = (*tet)->x[i]) : (*tet)->x[i];
		((*tet)->y[i] < m->miny) ? (m->miny = (*tet)->y[i]) : (*tet)->y[i];
		((*tet)->x[i] > m->maxx) ? (m->maxx = (*tet)->x[i]) : (*tet)->x[i];
		((*tet)->y[i] > m->maxy) ? (m->maxy = (*tet)->y[i]) : (*tet)->y[i];
	}
	if (m->minx > 0)
		change_coord(m->minx, (*tet)->x);
	if (m->miny > 0)
		change_coord(m->miny, (*tet)->y);
	(*tet)->width = m->maxx - m->minx;
	(*tet)->height = m->maxy - m->miny;
	free(m);
	return ((*tet));
}
