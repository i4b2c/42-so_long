/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erro_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaldas <icaldas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:57:34 by icaldas           #+#    #+#             */
/*   Updated: 2023/03/22 15:00:56 by icaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	free_fd(int fd, char *s, char *str)
{
	close (fd);
	free (s);
	free (str);
}

int	verificar_line(char *str)
{
	int		fd;
	int		temp;
	char	*s;

	temp = 0;
	fd = open(str, O_RDONLY);
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		if (temp != 0)
		{
			if (temp != ft_strlen(s))
			{
				free_fd(fd, s, str);
				return (1);
			}
		}
		temp = ft_strlen(s);
		free (s);
	}
	close (fd);
	return (0);
}
