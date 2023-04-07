/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:48:01 by marvin            #+#    #+#             */
/*   Updated: 2023/02/28 13:48:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	mudar_letra(t_data *data, int y, int x, int op)
{
	data->map.map[data->map.y + y][data->map.x + x] = 'P';
	if (op == 67)
		data->map.collect--;
	if (op == 69)
	{
		data->map.exit_x = data->map.x + x;
		data->map.exit_y = data->map.y + y;
	}
	if (data->map.exit_x - x == data->map.x - x
		&& data->map.exit_y - y == data->map.y - y)
		data->map.map[data->map.y][data->map.x] = 'E';
	else
		data->map.map[data->map.y][data->map.x] = '0';

}

void	mudar_posicao(t_data *data, int y, int x)
{
	int len_x;
	int len_y;

	len_x = data->map.x + x;
	len_y = data->map.y + y;
	mlx_put_image_to_window(data->mlx,data->win
		,data->map.player,len_x * 64,len_y * 64);
	if (data->map.exit_x - x == data->map.x - x
		&& data->map.exit_y - y == data->map.y - y)
		mlx_put_image_to_window(data->mlx,data->win
			,data->map.door,data->map.x * 64,data->map.y * 64);
	else
		mlx_put_image_to_window(data->mlx,data->win
			,data->map.grass,data->map.x * 64,data->map.y * 64);
}

void mudar_a(t_data *data, int op)
{
	mudar_letra(data, 0, -1, op);
	mudar_posicao(data,0,-1);
	data->map.x--;
}

void mudar_d(t_data *data, int op)
{
	mudar_letra(data, 0, 1, op);
	mudar_posicao(data,0,1);
	data->map.x++;
}

void mudar_s(t_data *data, int op)
{
	mudar_letra(data, 1, 0, op);
	mudar_posicao(data,1,0);
	data->map.y++;
}

void mudar_w(t_data *data, int op)
{
	mudar_letra(data, -1, 0, op);
	mudar_posicao(data,-1,0);
	data->map.y--;
}

int	key_handler(int keycode, t_data *data)
{
	int		op;

	op = 0;
	op = prox_numero(keycode, data);
	data->map.keycode = keycode;
	if (keycode == A && check_key(data, A) != 1)
		mudar_a(data,op);
	else if (keycode == D && check_key(data, D) != 1)
		mudar_d(data,op);
	else if (keycode == S && check_key(data, S) != 1)
		mudar_s(data,op);
	else if (keycode == W && check_key(data, W) != 1)
		mudar_w(data,op);
	else if (keycode == ESC)
		encerrar_jogo(data);
	return (0);
}

int	mouse_hook(t_data *data)
{
	encerrar_jogo(data);
	exit(0);
}
