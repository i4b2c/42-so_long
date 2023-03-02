/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erro.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:37:53 by marvin            #+#    #+#             */
/*   Updated: 2023/02/28 13:37:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	erro_vazio(char *str)
{
	char	*s;
	int		fd;
	int		i;

	i = 0;
	s = malloc(1);
	fd = open(str, O_RDONLY);
	read (fd, s, 1);
	if (!s[0])
		i = 1;
	else
		i = 0;
	free (s);
	close (fd);
	return (i);
}

int	verificar_ber(char *str)
{
	int		i;
	int		k;
	char	*frase;

	i = 0;
	frase = malloc(5 * sizeof(char));
	ft_strcpy(frase, ".ber");
	while (str[i] != '\0')
	{
		k = 0;
		while (str[i + k] == frase[k])
		{
			if (frase[k + 1] == '\0')
			{
				free(frase);
				return (0);
			}
			k++;
		}
		i++;
	}
	free(frase);
	return (1);
}

int	verificar_x(t_data data)
{
	int	i;

	i = 0;
	while (i < data.map.lin)
	{
		if (data.map.map[i][0] != '1'
			|| data.map.map[i][data.map.col - 1] != '1')
			return (1);
		i++;
	}
	return (0);
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

int	ver_erro(int x, int y, char *str, t_data data)
{
	int	erro;

	erro = 0;
	if (data.map.collect == 0 || data.map.exit != 1
		|| data.map.player_counter != 1)
		erro = 1;
	if (x == -1 || x == y)
		erro = 1;
	if ((verificar_ber(str)) != 0)
		erro = 1;
	if ((verificar_x(data) != 0) || (verificar_y(data) != 0))
		erro = 1;
	return (erro);
}
