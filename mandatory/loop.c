/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:16:32 by marvin            #+#    #+#             */
/*   Updated: 2023/04/12 20:16:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	atualizar(t_data *data)
{
	static int	j;
	static int	i;
	static int	k;
	static int	l;

	check_sprite_porta(data, &j);
	check_sprite_coin(data, &i);
	l++;
	k++;
	i++;
	return (0);
}

void	loop(t_data *data)
{
	mlx_hook(data->win, 2, 1, key_handler, data);
	mlx_hook(data->win, 17, 1, mouse_hook, data);
	mlx_loop(data->mlx);
}
