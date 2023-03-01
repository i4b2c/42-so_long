/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:39:39 by marvin            #+#    #+#             */
/*   Updated: 2023/02/28 13:39:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = s2[i];
	return (s1);
}

void	atribuir_col_e_lin(t_data *data, int x, int y)
{
	data->map.col = x;
	data->map.lin = y;
}

void	colocar_texto_e_acabar(int x, t_data *data)
{
	if (x == 1)
		write(1, "You Won!!\n", 10);
	else if (x == 2)
		write(1, "You Died,Try Again!\n", 20);
	encerrar_jogo(data);
}

void	get_imagens(t_data *data)
{
	int	x;
	int	y;

	data->map.cogumelo = mlx_xpm_file_to_image(data->mlx, COGUMELO, &x, &y);
	data->map.brick = mlx_xpm_file_to_image(data->mlx, BRICK, &x, &y);
	data->map.player = mlx_xpm_file_to_image(data->mlx, PLAYER, &x, &y);
	data->map.door = mlx_xpm_file_to_image(data->mlx, DOOR, &x, &y);
	data->map.grass = mlx_xpm_file_to_image(data->mlx, GRASS, &x, &y);
}
