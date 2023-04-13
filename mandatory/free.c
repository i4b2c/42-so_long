/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:40:24 by marvin            #+#    #+#             */
/*   Updated: 2023/02/28 13:40:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	free_total(t_data *data)
{
	int	i;

	i = data->map.lin - 1;
	while (i >= 0)
	{
		free(data->map.map[i]);
		i--;
	}
	free (data->map.map);
	mlx_loop_end(data->mlx);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->map.grass);
	mlx_destroy_image(data->mlx, data->map.door);
	mlx_destroy_image(data->mlx, data->map.door_open);
	mlx_destroy_image(data->mlx, data->map.brick);
	mlx_destroy_image(data->mlx, data->map.player);
	mlx_destroy_image(data->mlx, data->map.cogumelo);
	mlx_destroy_image(data->mlx, data->map.inimigo);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
