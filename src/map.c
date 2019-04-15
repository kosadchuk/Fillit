/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:05:13 by kosadchu          #+#    #+#             */
/*   Updated: 2019/02/13 21:33:28 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_solve(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->arr[i]);
		ft_putchar('\n');
		i++;
	}
}

int		one_sqrt(t_tetro *tetro, int count)
{
	if (count == 1 && tetro->width == 1 && tetro->height == 1)
		return (1);
	return (0);
}

int		map_size(t_tetro *tetro, int count)
{
	int		size;

	size = 3;
	count = count * 4;
	while (size * size < count)
		size++;
	if (one_sqrt(tetro, count) == 1)
		size = 2;
	return (size);
}

t_map	*new_map(int size)
{
	t_map	*map;
	int		x;
	int		y;

	map = ft_memalloc(sizeof(t_map));
	map->size = size;
	map->arr = (char **)ft_memalloc(sizeof(char *) * size);
	y = -1;
	while (++y < map->size)
	{
		map->arr[y] = ft_strnew(map->size);
		x = -1;
		while (++x < map->size)
			map->arr[y][x] = '.';
	}
	return (map);
}

void	free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		free(map->arr[i]);
		i++;
	}
	free(map->arr);
	free(map);
}
