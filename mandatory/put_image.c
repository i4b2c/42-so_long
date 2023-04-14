/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:21:09 by marvin            #+#    #+#             */
/*   Updated: 2023/04/12 20:21:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	sprite_porta(t_data *data, int i)
{
	colocar_imagem_door(data, i);
	mlx_put_image_to_window(data->mlx,
		data->win, data->map.door,
		64 * data->map.exit_x, 64 * data->map.exit_y);
}

void	colocar_imagem_coin(t_data *data, int x)
{
	mlx_destroy_image(data->mlx, data->map.cogumelo);
	if (x == 1)
		data->map.cogumelo = mlx_xpm_file_to_image(data->mlx,
				"./textures/coin2.xpm", &data->x1, &data->x2);
	else if (x == 2)
		data->map.cogumelo = mlx_xpm_file_to_image(data->mlx,
				"./textures/coin3.xpm", &data->x1, &data->x2);
	else if (x == 3)
		data->map.cogumelo = mlx_xpm_file_to_image(data->mlx,
				"./textures/coin4.xpm", &data->x1, &data->x2);
	else if (x == 4)
		data->map.cogumelo = mlx_xpm_file_to_image(data->mlx,
				"./textures/coin5.xpm", &data->x1, &data->x2);
	else if (x == 5)
		data->map.cogumelo = mlx_xpm_file_to_image(data->mlx,
				"./textures/coin6.xpm", &data->x1, &data->x2);
	else
		data->map.cogumelo = mlx_xpm_file_to_image(data->mlx,
				"./textures/coin1.xpm", &data->x1, &data->x2);
}

void	sprite_coin(t_data *data, int i)
{
	colocar_imagem_coin(data, i);
	colocar_cogumelo(data);
}

void	colocar_cogumelo(t_data *data)
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
			if (data->map.map[x][y] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->map.cogumelo, 64 * y, 64 * x);
			y++;
		}
		x++;
	}
}
