/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erro_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaldas <icaldas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:12:28 by icaldas           #+#    #+#             */
/*   Updated: 2023/03/22 14:13:14 by icaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
/*
void	get_map(t_data *data, int fd)
{
	char	*s;
	int		k;

	data->map.map = malloc((data->map.lin) * sizeof (char *));
	k = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		data->map.map[k] = ft_strtrim(s, "\n");
		data->map.map[k][data->map.col] = 0;
		free(s);
		k++;
	}
}

int	verificar_y(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.map.lin)
	{
		if (i == 0 || i == data.map.lin - 1)
		{
			j = 0;
			while (j < data.map.col)
			{
				if (data.map.map[i][j] != '1')
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

int	verificar_x(t_data data)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < data.map.lin)
	{
		if (data.map.map[i][0] != '1'
		|| data.map.map[i][data.map.col - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
*/
