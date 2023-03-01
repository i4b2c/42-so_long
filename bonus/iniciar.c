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

#include "../include/so_long_bonus.h"

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
	mlx_hook(data->win, 2, 1, key_handler, data);
	mlx_hook(data->win, 17, 1, mouse_hook, data);
	if (ver_erro(x, y, av[1], *data) == 1)
		encerrar_jogo_erro(data);
	render_map(data);
	mlx_loop(data->mlx);
}

void	iniciar(t_data *data)
{
	data->map.collect = 0;
	data->map.exit = 0;
	data->map.player_counter = 0;
	data->map.collect = 0;
	data->map.exit_x = 0;
	data->map.exit_y = 0;
	data->map.mov = 0;
	data->map.keycode = 0;
	data->x1 = 0;
	data->x2 = 0;
}
