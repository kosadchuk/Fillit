/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:06:27 by kosadchu          #+#    #+#             */
/*   Updated: 2019/02/14 14:53:51 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_pos(t_tetro *tetro, t_map *map, int x, int y)
{
	int		i;

	if ((y + tetro->height < map->size)
		&& (x + tetro->width < map->size))
	{
		i = 0;
		while (i < 4)
		{
			if (map->arr[y + tetro->y[i]][x + tetro->x[i]] != '.')
				return (1);
			if (map->arr[y + tetro->y[i]][x + tetro->x[i]] == '.')
				i++;
		}
	}
	else
		return (1);
	pass_tetro(tetro, map, x, y);
	return (0);
}

void		pass_tetro(t_tetro *tetro, t_map *map, int x, int y)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		map->arr[y + tetro->y[i]][x + tetro->x[i]] = tetro->abc;
		i++;
	}
}

void		del_last(t_tetro *tetro, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if (map->arr[i][j] == tetro->abc)
				map->arr[i][j] = '.';
			j++;
		}
		i++;
	}
}

int			backtrack(t_tetro *tetro, t_map *map)
{
	int		x;
	int		y;

	if (tetro == NULL)
		return (1);
	y = -1;
	while (++y < map->size)
	{
		x = -1;
		while (++x < map->size)
		{
			if (check_pos(tetro, map, x, y) == 0)
			{
				if (backtrack(tetro->next, map) == 1)
					return (1);
				else
				{
					if (g_omg++ > 2000000)
						return (0);
					del_last(tetro, map);
				}
			}
		}
	}
	return (0);
}

t_map		*solve(t_tetro *tetro, int count)
{
	t_map	*map;
	int		size;

	g_omg = 0;
	size = map_size(tetro, count);
	map = new_map(size);
	while (backtrack(tetro, map) == 0)
	{
		size++;
		free_map(map);
		map = new_map(size);
	}
	return (map);
}
