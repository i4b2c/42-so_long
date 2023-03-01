/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:48:23 by marvin            #+#    #+#             */
/*   Updated: 2023/02/28 13:48:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_x_y(int *x, int *y, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	*y = funcao_y(fd);
	fd = open(av[1], O_RDONLY);
	*x = funcao_x(fd);
	fd = open(av[1], O_RDONLY);
	return (fd);
}

char	ler_o_xpm(int fd)
{
	char		*buf;
	char		s;
	int			x;
	static int	i;

	x = 0;
	buf = malloc(1);
	while (x <= i)
	{
		if (x == i)
			read(fd, buf, 1);
		x++;
	}
	s = buf[0];
	free(buf);
	i++;
	return (s);
}
