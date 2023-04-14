/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:49:16 by marvin            #+#    #+#             */
/*   Updated: 2023/02/28 13:49:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_key(t_data *data, int x)
{
	int			k;

	k = 0;
	if (check_end(data, x) == 1 || check_end(data, x) == 2)
		colocar_texto_e_acabar(check_end(data, x), data);
	else if (x == A
		&& data->map.map[data->map.y][data->map.x - 1] == '1')
			k = 1;
	else if (x == D
		&& data->map.map[data->map.y][data->map.x + 1] == '1')
			k = 1;
	else if (x == W
		&& data->map.map[data->map.y - 1][data->map.x] == '1')
			k = 1;
	else if (x == S
		&& data->map.map[data->map.y + 1][data->map.x] == '1')
			k = 1;
	return (k);
}

int	prox_numero(int keycode, t_data *data)
{
	int	i;

	i = 0;
	if (keycode == A)
		i = data->map.map[data->map.y][data->map.x - 1];
	if (keycode == D)
		i = data->map.map[data->map.y][data->map.x + 1];
	if (keycode == S)
		i = data->map.map[data->map.y + 1][data->map.x];
	if (keycode == W)
		i = data->map.map[data->map.y - 1][data->map.x];
	return (i);
}

int	check_end(t_data *data, int x)
{
	data->map.exit_suc = 0;
	if (x == A)
		return (act_a(data));
	else if (x == D)
		return (act_d(data));
	else if (x == W)
		return (act_w(data));
	else if (x == S)
		return (act_s(data));
	return (0);
}

void	colocar_movimento(int i, t_data *data)
{
	char	*str;

	str = ft_itoa(i);
	mlx_put_image_to_window(data->mlx, data->win, data->map.brick, 64, 0);
	mlx_string_put(data->mlx, data->win, 20, 32, WHITE, "movimentos:");
	mlx_string_put(data->mlx, data->win, 96, 32, WHITE, str);
	free (str);
}
