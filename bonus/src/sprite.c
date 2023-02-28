/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:52:55 by marvin            #+#    #+#             */
/*   Updated: 2023/02/28 13:52:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	colocar_imagem_door(t_data *data, int x)
{
	if (x == 1)
		data->map.door = mlx_xpm_file_to_image(data->mlx,
				"./textures/door2.xpm", &data->x1, &data->x2);
	else if (x == 2)
		data->map.door = mlx_xpm_file_to_image(data->mlx,
				"./textures/door3.xpm", &data->x1, &data->x2);
	else if (x == 3)
		data->map.door = mlx_xpm_file_to_image(data->mlx,
				"./textures/door4.xpm", &data->x1, &data->x2);
	else if (x == 4)
		data->map.door = mlx_xpm_file_to_image(data->mlx,
				"./textures/door5.xpm", &data->x1, &data->x2);
	else if (x == 5)
		data->map.door = mlx_xpm_file_to_image(data->mlx,
				DOOR_OPEN, &data->x1, &data->x2);
}

void	sprite_porta(t_data *d, int x, int y)
{
	if (d->map.collect == -1)
		return ;
	mlx_destroy_image(d->mlx, d->map.door);
	colocar_imagem_door(d, 1);
	mlx_put_image_to_window(d->mlx, d->win, d->map.door, 64 * x, 64 * y);
	usleep(100000);
	mlx_destroy_image(d->mlx, d->map.door);
	colocar_imagem_door(d, 2);
	mlx_put_image_to_window(d->mlx, d->win, d->map.door, 64 * x, 64 * y);
	usleep(100000);
	mlx_destroy_image(d->mlx, d->map.door);
	colocar_imagem_door(d, 3);
	mlx_put_image_to_window(d->mlx, d->win, d->map.door, 64 * x, 64 * y);
	usleep(100000);
	mlx_destroy_image(d->mlx, d->map.door);
	colocar_imagem_door(d, 4);
	mlx_put_image_to_window(d->mlx, d->win, d->map.door, 64 * x, 64 * y);
	usleep(100000);
	mlx_destroy_image(d->mlx, d->map.door);
	colocar_imagem_door(d, 5);
	mlx_put_image_to_window(d->mlx, d->win, d->map.door, 64 * x, 64 * y);
	d->map.collect = -1;
}

void	colocar_fantasma_direcao(t_data *data, int x, int y)
{
	int	x_1;
	int	y_2;

	if (data->map.keycode == A)
	{
		mlx_destroy_image(data->mlx, data->map.player);
		data->map.player = mlx_xpm_file_to_image(data->mlx, PLAYER, &x_1, &y_2);
	}
	else if (data->map.keycode == D)
	{
		mlx_destroy_image(data->mlx, data->map.player);
		data->map.player = mlx_xpm_file_to_image(data->mlx,
				PLAYER_R, &x_1, &y_2);
	}
	mlx_put_image_to_window(data->mlx,
		data->win, data->map.player, 64 * x, 64 * y);
}
