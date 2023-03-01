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

int	key_handler(int keycode, t_data *data)
{
	int		op;

	op = 0;
	op = prox_numero(keycode, data);
	data->map.keycode = keycode;
	if (keycode == A && check_key(data, A) != 1)
		mudar_letra(data, 0, -1, op);
	else if (keycode == D && check_key(data, D) != 1)
		mudar_letra(data, 0, 1, op);
	else if (keycode == S && check_key(data, S) != 1)
		mudar_letra(data, 1, 0, op);
	else if (keycode == W && check_key(data, W) != 1)
		mudar_letra(data, -1, 0, op);
	else if (keycode == ESC)
		encerrar_jogo(data);
	render_map(data);
	return (0);
}

int	mouse_hook(t_data *data)
{
	encerrar_jogo(data);
	exit(0);
}
