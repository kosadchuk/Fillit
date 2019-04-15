/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:59:54 by kosadchu          #+#    #+#             */
/*   Updated: 2019/02/14 16:53:56 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_chains(char *str)
{
	int		i;
	int		chain;

	i = 0;
	chain = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			((i + 1) < 20 && str[i + 1] == '#') ? chain++ : chain;
			((i - 1) >= 0 && str[i - 1] == '#') ? chain++ : chain;
			((i + 5) < 20 && str[i + 5] == '#') ? chain++ : chain;
			((i - 5) >= 0 && str[i - 5] == '#') ? chain++ : chain;
		}
		i++;
	}
	if (chain != 6 && chain != 8)
		ft_error("error\n");
}

int		valid_symb(char *str)
{
	int		i;
	int		hash;

	i = 0;
	hash = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if ((str[i] != '#' && str[i] != '.')
			|| (str[i] == '#' && ++hash > 4))
				return (1);
		}
		else if (str[i] != '\n')
			return (1);
		i++;
	}
	check_chains(str);
	return (0);
}

int		check_len(char *buf, int bytes)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	while (i < bytes)
	{
		j = -1;
		count = 0;
		while (++j < 20)
		{
			if (buf[i] == '.' || buf[i] == '#')
				count++;
			i++;
		}
		if ((buf[i] != '\n' && buf[i] != '\0') || count != 16)
			return (1);
		i++;
	}
	return (0);
}

int		check_str(char *buf, int bytes)
{
	char	*str;
	int		i;

	i = -1;
	while (++i < bytes)
	{
		if (check_len(buf, bytes) != 0)
			return (1);
		if (buf[i] == '\n' && buf[i + 1] == '\n')
		{
			if (((buf[i + 2] != '#') && (buf[i + 2] != '.')) || i < 19)
				return (1);
			if (valid_symb((str = ft_strsub(buf, i - 19, 21))) != 0)
				return (1);
			free(str);
			i++;
		}
		if (buf[i] == '\n' && buf[i + 1] == '\0')
		{
			if (valid_symb((str = ft_strsub(buf, i - 19, 20))) != 0)
				return (1);
			free(str);
		}
	}
	return (0);
}

char	*ft_read(int fd)
{
	char	buf[600];
	char	*string;
	int		bytes;

	if ((bytes = read(fd, buf, 600)) > 545 || (bytes < 20) || bytes < 0)
		return (0);
	buf[bytes] = '\0';
	if ((buf[bytes] == '\0' && buf[bytes - 1] != '\n')
	|| (buf[bytes] == '\0' && buf[bytes - 2] == '\n')
	|| check_str(buf, bytes) != 0)
		return (NULL);
	string = ft_strsub(buf, 0, bytes);
	return (string);
}
