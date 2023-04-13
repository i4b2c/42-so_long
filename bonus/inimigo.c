/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inimigo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:19:38 by marvin            #+#    #+#             */
/*   Updated: 2023/04/12 20:19:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	colocar_inimigo(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map.lin)
	{
		y = 0;
		while (data->map.map[x][y] != '\0')
		{
			if (data->map.map[x][y] == 'N')
				mlx_put_image_to_window(data->mlx, data->win, data->map.inimigo,
					64 * y, 64 * x);
			y++;
		}
		x++;
	}
}

void	mudar_posicao_inmg(t_data *data, int x, int y, int num)
{
	if (num == 1)
		data->map.map[x][y - 1] = 'n';
	else if (num == 2)
		data->map.map[x][y + 1] = 'n';
	else if (num == 3)
		data->map.map[x - 1][y] = 'n';
	else if (num == 4)
		data->map.map[x + 1][y] = 'n';
	data->map.map[x][y] = '0';
}

void	recolocar_inimigo(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map.lin)
	{
		y = 0;
		while (data->map.map[x][y] != '\0')
		{
			if (data->map.map[x][y] == '0')
				mlx_put_image_to_window(data->mlx, data->win,
					data->map.grass, 64 * y, 64 * x);
			else if (data->map.map[x][y] == 'n')
			{
				mlx_put_image_to_window(data->mlx, data->win,
					data->map.inimigo, 64 * y, 64 * x);
				data->map.map[x][y] = 'N';
			}
			y++;
		}
		x++;
	}
}

void	mudar_inimigo(t_data *data)
{
	int	x;
	int	y;
	int	num;

	x = 0;
	y = 0;
	while (x < data->map.lin)
	{
		y = 0;
		while (data->map.map[x][y] != '\0')
		{
			if (data->map.map[x][y] == 'N')
			{
				num = rand() % 5;
				if (check(data, x, y, num))
					mudar_posicao_inmg(data, x, y, num);
				else
					data->map.map[x][y] = 'n';
			}
			y++;
		}
		x++;
	}
	recolocar_inimigo(data);
}

void	check_mov_inimigo(t_data *data, int *k)
{
	if (*k == 5000)
	{
		mudar_inimigo(data);
		*k = 0;
	}
}
