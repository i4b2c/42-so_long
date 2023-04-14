/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_change.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:15:46 by marvin            #+#    #+#             */
/*   Updated: 2023/04/12 20:15:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mudar_a(t_data *data, int op)
{
	int	x;
	int	y;

	mlx_destroy_image(data->mlx, data->map.player);
	data->map.player = mlx_xpm_file_to_image(data->mlx,
			PLAYER_R, &y, &x);
	mudar_letra(data, 0, -1, op);
	mudar_posicao(data, 0, -1);
	ft_printf("movimentos: %d\n", data->map.mov++);
	data->map.x--;
}

void	mudar_d(t_data *data, int op)
{
	int	x;
	int	y;

	mlx_destroy_image(data->mlx, data->map.player);
	data->map.player = mlx_xpm_file_to_image(data->mlx,
			PLAYER, &x, &y);
	mudar_letra(data, 0, 1, op);
	mudar_posicao(data, 0, 1);
	ft_printf("movimentos: %d\n", data->map.mov++);
	data->map.x++;
}

void	mudar_s(t_data *data, int op)
{
	mudar_letra(data, 1, 0, op);
	mudar_posicao(data, 1, 0);
	ft_printf("movimentos: %d\n", data->map.mov++);
	data->map.y++;
}

void	mudar_w(t_data *data, int op)
{
	mudar_letra(data, -1, 0, op);
	mudar_posicao(data, -1, 0);
	ft_printf("movimentos: %d\n", data->map.mov++);
	data->map.y--;
}
