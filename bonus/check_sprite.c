/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:17:15 by marvin            #+#    #+#             */
/*   Updated: 2023/04/12 20:17:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	check_sprite_inimigo(t_data *data, int *l)
{
	int	x;
	int	y;

	if (*l == 5000)
	{
		mlx_destroy_image(data->mlx, data->map.inimigo);
		data->map.inimigo = mlx_xpm_file_to_image(data->mlx,
				"./textures/goomba1.xpm", &x, &y);
		colocar_inimigo(data);
	}
	else if (*l == 10000)
	{
		mlx_destroy_image(data->mlx, data->map.inimigo);
		data->map.inimigo = mlx_xpm_file_to_image(data->mlx,
				"./textures/goomba2.xpm", &x, &y);
		colocar_inimigo(data);
		*l = 0;
	}
}

void	check_sprite_coin(t_data *data, int *i)
{
	if (*i == 500)
		sprite_coin(data, 1);
	else if (*i == 1000)
		sprite_coin(data, 2);
	else if (*i == 1500)
		sprite_coin(data, 3);
	else if (*i == 2000)
		sprite_coin(data, 4);
	else if (*i == 2500)
		sprite_coin(data, 5);
	else if (*i == 3000)
	{
		sprite_coin(data, 6);
		*i = 0;
	}
}

void	check_sprite_porta(t_data *data, int *j)
{
	if (data->map.collect == 0 && *j >= 0)
	{
		if (*j > 1000)
			*j = -2;
		else if (*j == 200)
			sprite_porta(data, 1);
		else if (*j == 400)
			sprite_porta(data, 2);
		else if (*j == 600)
			sprite_porta(data, 3);
		else if (*j == 800)
			sprite_porta(data, 4);
		else if (*j == 1000)
			sprite_porta(data, 5);
		(*j)++;
	}
}

int	check(t_data *data, int x, int y, int num)
{
	if (num == 1)
	{
		if (data->map.map[x][y - 1] == '0')
			return (1);
	}
	else if (num == 2)
	{
		if (data->map.map[x][y + 1] == '0')
			return (1);
	}
	else if (num == 3)
	{
		if (data->map.map[x - 1][y] == '0')
			return (1);
	}
	else if (num == 4)
	{
		if (data->map.map[x + 1][y] == '0')
			return (1);
	}
	return (0);
}
