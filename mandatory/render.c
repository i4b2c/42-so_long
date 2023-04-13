/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:51:01 by marvin            #+#    #+#             */
/*   Updated: 2023/02/28 13:51:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	put_imagem(t_data *data, int op, int len_x, int len_y)
{
	if (op == 1)
		mlx_put_image_to_window(data->mlx,
			data->win, data->map.brick, 64 * len_x, 64 * len_y);
	else if (op == 2)
	{
		data->map.exit_x = len_x;
		data->map.exit_y = len_y;
		mlx_put_image_to_window(data->mlx,
			data->win, data->map.door, 64 * len_x, 64 * len_y);
	}
	else if (op == 3)
	{
		data->map.x = len_x;
		data->map.y = len_y;
		colocar_fantasma_direcao(data, len_x, len_y);
	}
	else if (op == 4)
		mlx_put_image_to_window(data->mlx,
			data->win, data->map.cogumelo, 64 * len_x, 64 * len_y);
	else
		mlx_put_image_to_window(data->mlx,
			data->win, data->map.grass, 64 * len_x, 64 * len_y);
}

void	ver_objetos(t_data *data)
{
	int	i;
	int	k;
	int	op;

	k = 0;
	while (k < data->map.lin)
	{
		i = 0;
		while (data->map.map[k][i] != '\0')
		{
			op = options_map(data, k, i);
			if (op == 2)
				data->map.exit++;
			else if (op == 3)
				data->map.player_counter++;
			else if (op == 4)
				data->map.collect++;
			i++;
		}
		k++;
	}
}

void	render_map(t_data *data)
{
	int	i;
	int	k;
	int	op;

	k = 0;
	while (k < data->map.lin)
	{
		i = 0;
		while (data->map.map[k][i] != '\0')
		{
			op = options_map(data, k, i);
			if (op == -1)
				encerrar_jogo_erro(data);
			put_imagem(data, op, i, k);
			i++;
		}
		k++;
	}
}

void	get_map(t_data *data, int fd)
{
	char	*s;
	int		k;

	data->map.map = malloc((data->map.lin) * sizeof (char *));
	k = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		data->map.map[k] = ft_strtrim(s, "\n");
		data->map.map[k][data->map.col] = 0;
		free(s);
		k++;
	}
}

int	options_map(t_data *data, int k, int i)
{
	if (data->map.map[k][i] == '0')
		return (0);
	else if (data->map.map[k][i] == '1')
		return (1);
	else if (data->map.map[k][i] == 'E')
		return (2);
	else if (data->map.map[k][i] == 'P')
		return (3);
	else if (data->map.map[k][i] == 'C')
		return (4);
	return (-1);
}
