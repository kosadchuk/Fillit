/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:19:29 by kosadchu          #+#    #+#             */
/*   Updated: 2019/02/15 20:15:14 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_map
{
	int				size;
	char			**arr;
}					t_map;
typedef struct		s_tetro
{
	char			abc;
	int				width;
	int				height;
	int				x[4];
	int				y[4];
	struct s_tetro	*next;
}					t_tetro;

typedef struct		s_mn_mx
{
	int				minx;
	int				maxx;
	int				miny;
	int				maxy;
}					t_mn_mx;

int					g_omg;
void				ft_error(char *errstr);
void				check_chains(char *str);
int					valid_symbl(char *str);
int					valid_file(int fd);
char				*ft_read(int fd);
int					save_string(t_tetro **list, char *str);
t_tetro				*save_tetro(char *str, char letter);
char				*cut_str(char *str, int *i);
void				min_max(t_mn_mx **m);
void				change_coord(int min, int *arr);
t_tetro				*width_height(t_tetro **tetro);
int					map_size(t_tetro *tetro, int count);
t_map				*new_map(int size);
void				print_solve(t_map *map);
t_map				*solve(t_tetro *list, int count);
int					one_sqrt(t_tetro *tetro, int count);
void				free_map(t_map *map);
void				pass_tetro(t_tetro *tetro, t_map *map, int x, int y);
int					backtrack(t_tetro *tetro, t_map *map);
int					check_pos(t_tetro *tetro, t_map *map, int x, int y);

#endif
