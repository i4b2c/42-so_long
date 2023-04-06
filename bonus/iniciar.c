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

int atualizar(t_data *data)
{
	static int j = 0;
	static int i = 0;
	int x, y;
	//static void *temp;
	//temp = mlx_xpm_file_to_image(data->mlx,BRICK,&x,&y);
	if(data->map.collect == 0)
	{
		if(j > 25)
			data->map.collect = -1;
		else if(j == 5)
		{
			mlx_destroy_image(data->mlx, data->map.door);
			colocar_imagem_door(data, 1);
			render_map(data);
			colocar_movimento(data->map.mov,data);
		}
		else if(j == 10)
		{
			mlx_destroy_image(data->mlx, data->map.door);
			colocar_imagem_door(data, 2);
			render_map(data);
			colocar_movimento(data->map.mov,data);
		}
		else if(j == 15)
		{
			mlx_destroy_image(data->mlx, data->map.door);
			colocar_imagem_door(data, 3);
			render_map(data);
			colocar_movimento(data->map.mov,data);
		}
		else if(j == 20)
		{
			mlx_destroy_image(data->mlx, data->map.door);
			colocar_imagem_door(data, 4);
			render_map(data);
			colocar_movimento(data->map.mov,data);
		}
		else if(j == 25)
		{
			mlx_destroy_image(data->mlx, data->map.door);
			colocar_imagem_door(data, 5);
			render_map(data);
			colocar_movimento(data->map.mov,data);
		}
		j++;
	}
	//mlx_string_put(data->mlx,data->win,100,100,WHITE,"boas");
	if(i == 100)
	{
		mlx_destroy_image(data->mlx, data->map.inimigo);
		data->map.inimigo = mlx_xpm_file_to_image(data->mlx,BOY,&x,&y);
		render_map(data);
	}
	else if(i == 200)
	{
		mlx_destroy_image(data->mlx, data->map.inimigo);
		data->map.inimigo = mlx_xpm_file_to_image(data->mlx,GRASS,&x,&y);
		render_map(data);
		i = 0;
	}
	colocar_movimento(data->map.mov,data);
	i++;
	return 0;
}

void loop(t_data *data)
{
	mlx_hook(data->win, 2, 1, key_handler, data);
	mlx_hook(data->win, 17, 1, mouse_hook, data);
	render_map(data);
	//mlx_loop_hook(data->mlx,&atualizar,data);
	mlx_loop(data->mlx);
}

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
	data->map.mov = 0;
	data->map.keycode = 0;
	data->x1 = 0;
	data->x2 = 0;
}
