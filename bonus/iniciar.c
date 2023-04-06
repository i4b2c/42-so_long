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

void colocar_inimigo(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(x < data->map.lin)
	{
		y = 0;
		while(data->map.map[x][y] != '\0')
		{
			if(data->map.map[x][y] == 'N')
				mlx_put_image_to_window(data->mlx, data->win, data->map.inimigo,
			64 * y, 64 * x);
			y++;
		}
		x++;
	}
}

void colocar_cogumelo(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(x < data->map.lin)
	{
		y = 0;
		while(data->map.map[x][y] != '\0')
		{
			if(data->map.map[x][y] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->map.cogumelo,
			64 * y, 64 * x);
			y++;
		}
		x++;
	}
}

int check(t_data *data , int x, int y, int num)
{
	if(num == 1)
	{
		if(data->map.map[x][y-1] == '0')
			return 1;
	}
	else if(num == 2)
	{
		if(data->map.map[x][y+1] == '0')
			return 1;
	}
	else if(num == 3)
	{
		if(data->map.map[x-1][y] == '0')
			return 1;
	}
	else if(num == 4)
	{
		if(data->map.map[x+1][y] == '0')
			return 1;
	}
	return 0;
}

void mudar_posicao_inmg(t_data *data , int x, int y, int num)
{
	if(num == 1)
		data->map.map[x][y-1] = 'n';
	else if(num == 2)
		data->map.map[x][y+1] = 'n';
	else if(num == 3)
		data->map.map[x-1][y] = 'n';
	else if(num == 4)
		data->map.map[x+1][y] = 'n';
	data->map.map[x][y] = '0';
}

void recolocar_inimigo(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(x < data->map.lin)
	{
		y = 0;
		while(data->map.map[x][y] != '\0')
		{
			if(data->map.map[x][y] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->map.grass,
			64 * y, 64 * x);
			else if(data->map.map[x][y] == 'n')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->map.inimigo,
			64 * y, 64 * x);
				data->map.map[x][y] = 'N';
			}
			y++;
		}
		x++;
	}
}

void mudar_inimigo(t_data *data)
{
	int x;
	int y;
	int num;

	x = 0;
	y = 0;
	while(x < data->map.lin)
	{
		y = 0;
		while(data->map.map[x][y] != '\0')
		{
			if(data->map.map[x][y] == 'N')
			{
				num = rand()%4;

				if(check(data,x,y,num))
				{
					//printf("a");
					mudar_posicao_inmg(data,x,y,num);
				}
				else
					data->map.map[x][y] = 'n';
			}
			y++;
		}
		x++;
	}
	recolocar_inimigo(data);
}

int atualizar(t_data *data)
{
	static int j;
	static int i;
	static int k;
	int x, y;
	if(data->map.collect == 0 && j >= 0)
	{
		if(j > 250)
			j = -2;
		else if(j == 50)
		{
			mlx_destroy_image(data->mlx, data->map.door);
			colocar_imagem_door(data, 1);
			mlx_put_image_to_window(data->mlx,
				data->win, data->map.door, 64 * data->map.exit_x, 64 * data->map.exit_y);
		}
		else if(j == 100)
		{
			mlx_destroy_image(data->mlx, data->map.door);
			colocar_imagem_door(data, 2);
			mlx_put_image_to_window(data->mlx,
				data->win, data->map.door, 64 * data->map.exit_x, 64 * data->map.exit_y);
		}
		else if(j == 150)
		{
			mlx_destroy_image(data->mlx, data->map.door);
			colocar_imagem_door(data, 3);
			mlx_put_image_to_window(data->mlx,
				data->win, data->map.door, 64 * data->map.exit_x, 64 * data->map.exit_y);
		}
		else if(j == 200)
		{
			mlx_destroy_image(data->mlx, data->map.door);
			colocar_imagem_door(data, 4);
			mlx_put_image_to_window(data->mlx,
				data->win, data->map.door, 64 * data->map.exit_x, 64 * data->map.exit_y);
		}
		else if(j == 250)
		{
			mlx_destroy_image(data->mlx, data->map.door);
			colocar_imagem_door(data, 5);
			mlx_put_image_to_window(data->mlx,
				data->win, data->map.door, 64 * data->map.exit_x, 64 * data->map.exit_y);
		}
		j++;
	}
	if(i == 500)
	{
		mlx_destroy_image(data->mlx, data->map.cogumelo);
		data->map.cogumelo = mlx_xpm_file_to_image(data->mlx,"./textures/coin2.xpm",&x,&y);
		colocar_cogumelo(data);
	}
	else if(i == 1000)
	{
		mlx_destroy_image(data->mlx, data->map.cogumelo);
		data->map.cogumelo = mlx_xpm_file_to_image(data->mlx,"./textures/coin3.xpm",&x,&y);
		colocar_cogumelo(data);
	}
	else if(i == 1500)
	{
		mlx_destroy_image(data->mlx, data->map.cogumelo);
		data->map.cogumelo = mlx_xpm_file_to_image(data->mlx,"./textures/coin4.xpm",&x,&y);
		colocar_cogumelo(data);
	}
	else if(i == 2000)
	{
		mlx_destroy_image(data->mlx, data->map.cogumelo);
		data->map.cogumelo = mlx_xpm_file_to_image(data->mlx,"./textures/coin5.xpm",&x,&y);
		colocar_cogumelo(data);
	}
	else if(i == 2500)
	{
		mlx_destroy_image(data->mlx, data->map.cogumelo);
		data->map.cogumelo = mlx_xpm_file_to_image(data->mlx,"./textures/coin6.xpm",&x,&y);
		colocar_cogumelo(data);
	}
	else if(i == 3000)
	{
		mlx_destroy_image(data->mlx, data->map.cogumelo);
		data->map.cogumelo = mlx_xpm_file_to_image(data->mlx,"./textures/coin1.xpm",&x,&y);
		colocar_cogumelo(data);
		i = 0;
	}
	if(k == 5000)
	{
		mudar_inimigo(data);//muda as posicoes do N por n e a direcao depois atualiza de novo para N
		k = 0;
	}
	k++;
	colocar_movimento(data->map.mov,data);
	i++;
	return 0;
}

void loop(t_data *data)
{
	mlx_hook(data->win, 2, 1, key_handler, data);
	mlx_hook(data->win, 17, 1, mouse_hook, data);
	mlx_loop_hook(data->mlx,&atualizar,data);
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
	data->map.mov = 0;
	data->map.keycode = 0;
	data->x1 = 0;
	data->x2 = 0;
}
