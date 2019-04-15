/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:30:39 by kosadchu          #+#    #+#             */
/*   Updated: 2019/02/14 16:55:03 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			free_tetro(t_tetro *tetro)
{
	while (tetro)
	{
		free(tetro);
		tetro = tetro->next;
	}
}

void			ft_error(char *errstr)
{
	ft_putstr(errstr);
	exit(1);
}

int				main(int argc, char **argv)
{
	t_tetro		*tetro;
	t_map		*map;
	int			count;
	char		*str;

	if (argc != 2)
		ft_error("usage: ./fillit tetriminos_file\n");
	if ((str = ft_read(open(argv[1], O_RDONLY))) == NULL)
		ft_error("error\n");
	count = save_string(&tetro, str);
	map = solve(tetro, count);
	print_solve(map);
	free_map(map);
	free_tetro(tetro);
	return (0);
}
