/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iniciar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:48:37 by marvin            #+#    #+#             */
/*   Updated: 2023/02/28 13:48:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	iniciar_jogo(t_data *data, char **av)
{
	int	fd;
	int	x;
	int	y;

	iniciar(data);
	data->mlx = mlx_init();
	fd = get_x_y(&x, &y, av);
	atribuir_col_e_lin(data, x, y);
	get_map(data, fd);
	ver_objetos(data);
	get_imagens(data);
	close(fd);
	data->win = mlx_new_window(data->mlx, x * 64, y * 64, "so_long");
	render_map(data);
	loop(data);
}

void	iniciar(t_data *data)
{
	data->map.collect = 0;
	data->map.exit = 0;
	data->map.player_counter = 0;
	data->map.collect = 0;
	data->map.exit_x = 0;
	data->map.exit_y = 0;
	data->map.mov = 1;
	data->map.keycode = 0;
	data->x1 = 0;
	data->x2 = 0;
}
