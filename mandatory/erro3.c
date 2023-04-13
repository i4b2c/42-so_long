/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erro3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:50:53 by marvin            #+#    #+#             */
/*   Updated: 2023/04/09 21:50:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	extra(char *str)
{
	int		fd;
	char	*s;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	s = ft_calloc(1024, 1);
	read(fd, s, 1024);
	while (s[i])
		i++;
	if (s[i - 1] == '\n')
	{
		free (s);
		close (fd);
		return (0);
	}
	free (s);
	close (fd);
	return (1);
}

int	contar_linha(char *str)
{
	int		fd;
	char	*s;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		free (s);
		i++;
	}
	close(fd);
	return (i);
}

char	**replicar_map(char *av)
{
	char	*s;
	char	**str;
	int		k;
	int		fd;

	fd = open(av, O_RDONLY);
	str = malloc((contar_linha(av) + 1) * sizeof (char *));
	k = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		str[k] = ft_strtrim(s, "\n");
		str[k][ft_strlen(str[k])] = 0;
		free (s);
		k++;
	}
	str[k] = NULL;
	close (fd);
	return (str);
}

int	check_path_valid(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != 0)
		{
			if (str[i][j] == 'P' || str[i][j] == 'C'
				|| str[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	get_player(char **str, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != 0)
		{
			if (str[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
