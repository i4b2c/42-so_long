/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erro2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:50:10 by marvin            #+#    #+#             */
/*   Updated: 2023/04/09 21:50:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_side_ff(char **str, int x, int y)
{
	if (str[y][x + 1] == '2')
		return (1);
	if (str[y][x - 1] == '2')
		return (1);
	if (str[y + 1][x] == '2')
		return (1);
	if (str[y - 1][x] == '2')
		return (1);
	return (0);
}

void	flood_fill(char **str, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	str[y][x] = '2';
	while (str[i])
	{
		j = 0;
		while (str[i][j] != 0 && str[i][j] != '\n')
		{
			if (str[i][j] != '1' && str[i][j] != '2')
			{
				if (check_side_ff(str, j, i))
				{
					str[i][j] = '2';
					i = 0;
					j = 0;
				}
			}
			j++;
		}
		i++;
	}
}

void	free_path(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}

int	check_path(char *str)
{
	char	**s;
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	s = replicar_map(str);
	get_player(s, &x, &y);
	flood_fill(s, x, y);
	i = check_path_valid(s);
	free_path(s);
	return (i);
}

void	check_p_e_c(char *str, int *p, int *e, int *c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == 'P')
			(*p)++;
		else if (str[i] == 'E')
			(*e)++;
		else if (str[i] == 'C')
			(*c)++;
		i++;
	}
}
