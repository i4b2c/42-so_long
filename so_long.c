/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaldas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:09:58 by icaldas           #+#    #+#             */
/*   Updated: 2023/02/07 17:01:06 by icaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


char ler_o_xpm(int fd);
void render_map(t_data *data);

void mudar_letra(t_data *data,int y,int x,int op,int keycode)
{
	(void)keycode;

	data->map.map[data->map.y+y][data->map.x+x] = 'P';
	if(op == 67)
		data->map.collect--;
	if(op == 69)
	{
		data->map.exit_x = data->map.x+x;
		data->map.exit_y = data->map.y+y;
	}
	if(data->map.exit_x-x == data->map.x-x 
			&& data->map.exit_y-y == data->map.y-y)
	{
		data->map.map[data->map.y][data->map.x] = 'E';
	}

	else
		data->map.map[data->map.y][data->map.x] = '0';
}

void get_imagens(t_data *data)
{
	int x;
	int y;

	data->map.cogumelo = mlx_xpm_file_to_image(data->mlx, COGUMELO , &x,&y);
	data->map.brick = mlx_xpm_file_to_image(data->mlx, BRICK , &x,&y);
	data->map.player = mlx_xpm_file_to_image(data->mlx, PLAYER , &x,&y);
	data->map.door = mlx_xpm_file_to_image(data->mlx, DOOR , &x,&y);
	data->map.grass = mlx_xpm_file_to_image(data->mlx, GRASS , &x,&y);
}

int funcao_x(int fd)
{
	char *s;
	int x;
	int temp;
	s = get_next_line(fd);
	x = ft_strlen(s)-1;
	temp = x;
	free(s);
	while((s = get_next_line(fd)))
	{
		x = ft_strlen(s)-1;
		free(s);
		if(temp != x)
			return (-1);
	}
	return x;
}

int funcao_y(int fd)
{
	char *s;
	int y;
	y = 0;
	while((s = get_next_line(fd)))
	{
		y++;
		free(s);
	}
	return y;
}




int check_end(t_data *data, int x)
{
	data->map.exit_suc = 0;
	if(x == A && data->map.collect == 0)
	{
		if(data->map.map[data->map.y][data->map.x-1] == 'E')
			return 1;
	}
	else if(x == D && data->map.collect == 0)
	{
		if(data->map.map[data->map.y][data->map.x+1] == 'E')
			return 1;
	}
	else if(x == W && data->map.collect == 0)
	{
		if(data->map.map[data->map.y-1][data->map.x] == 'E')
			return 1;
	}
	else if(x == S && data->map.collect == 0)
	{
		if(data->map.map[data->map.y+1][data->map.x] == 'E')
			return 1;
	}
	else
		data->map.exit_suc = 0;
	return (0);
}
int check_key(t_data *data, int x)
{
	if(check_end(data,x) == 1)
	{
		exit(0);
		return (0);
	}
	if(x == A)
	{
		if(data->map.map[data->map.y][data->map.x-1] == '1')
			return 1;
	}
	else if(x == D)
	{
		if(data->map.map[data->map.y][data->map.x+1] == '1')
			return 1;
	}
	else if(x == W)
	{
		if(data->map.map[data->map.y-1][data->map.x] == '1')
			return 1;
	}
	else if(x == S)
	{
		if(data->map.map[data->map.y+1][data->map.x] == '1')
			return 1;
	}
	return 0;
}

int prox_numero(int keycode, t_data *data)
{
	int i;

	i = 0;
	if(keycode == A)
		i = data->map.map[data->map.y][data->map.x-1];
	if(keycode == D)
		i = data->map.map[data->map.y][data->map.x+1];
	if(keycode == S)
		i = data->map.map[data->map.y+1][data->map.x];
	if(keycode == W)
		i = data->map.map[data->map.y-1][data->map.x];
	return i;
}

int key_handler(int keycode, t_data *data)
{
	int op;

	op = 0;
	op = prox_numero(keycode, data);
	/*0 = 48 , 1 = 49 , C = 67 , E = 69 */
	if(keycode == A && check_key(data,A) != 1)
		mudar_letra(data,0,-1,op,keycode);
	else if(keycode == D && check_key(data,D) != 1)
		mudar_letra(data,0,1,op,keycode);
	else if(keycode == S && check_key(data,S) != 1)
		mudar_letra(data,1,0,op,keycode);
	else if(keycode == W && check_key(data,W) != 1)
		mudar_letra(data,-1,0,op,keycode);
	else if(keycode == ESC)
	{
		mlx_destroy_window(data->mlx,data->win);
		exit(0);
	}
	render_map(data);
	return 0;
}

int mouse_hook(void)
{
	exit(0);
	return 0;
}

char ler_o_xpm(int fd)
{
	char *buf;
	char s;
	int x;
	static int i;
	x = 0;
	buf = malloc(1);
	while(x <= i)
	{
		if(x == i)
			read(fd,buf,1);
		x++;
	}
	s = buf[0];
	free(buf);
	i++;
	return (s);
}

void get_map(t_data *data,int fd)
{
	char *s;
	int k;
	k = 0;
	data->map.map = malloc((data->map.lin)*sizeof(char *));
	while((s = get_next_line(fd)))
	{
		data->map.map[k] = ft_strtrim(s,"\n");
		data->map.map[k][data->map.col] = 0;
		k++;
		free(s);
	}
}

int options_map(t_data *data, int k, int i)
{
	if(data->map.map[k][i] == '0')
		return(0);
	else if(data->map.map[k][i] == '1')
		return(1);
	else if(data->map.map[k][i] == 'E')
		return(2);
	else if(data->map.map[k][i] == 'P')
		return(3);
	else if(data->map.map[k][i] == 'C')
		return(4);
	return -1;
}

void put_imagem(t_data *data, int op,int len_x, int len_y)
{

	if(op == 0)
		mlx_put_image_to_window(data->mlx,data->win,data->map.grass,32*len_x,32*len_y);
	if(op == 1)
		mlx_put_image_to_window(data->mlx,data->win,data->map.brick,32*len_x,32*len_y);
	if(op == 2)
		mlx_put_image_to_window(data->mlx,data->win,data->map.door,32*len_x,32*len_y);
	if(op == 3)
	{
		data->map.x = len_x;
		data->map.y = len_y;
		mlx_put_image_to_window(data->mlx,data->win,data->map.player,32*len_x,32*len_y);
	}
	if(op == 4)
		mlx_put_image_to_window(data->mlx,data->win,data->map.cogumelo,32*len_x,32*len_y);
}

void ver_objetos(t_data *data)
{
	int i;
	int k;
	int op;

	k = 0;
	while(k < data->map.lin)
	{
		i = 0;
		while(data->map.map[k][i] != '\0')
		{
			op = options_map(data,k,i);
			if(op == 2)
				data->map.exit++;
			else if(op == 3)
				data->map.player_counter++;	
			else if(op == 4)
				data->map.collect++;
			i++;
		}
		k++;
	}
}

void render_map(t_data *data)
{
	int i;
	int k;
	int op;
	k = 0;
	while(k < data->map.lin)
	{
		i = 0;
		while(data->map.map[k][i] != '\0')
		{
			op = options_map(data,k,i);
			if(op == -1)
			{
				mlx_destroy_window(data->mlx,data->win);
				printf("Error\n");
				exit(0);
			}
			put_imagem(data,op,i,k);
			i++;
		}
		k++;
	}
}

char    *ft_strcpy(char *s1, char *s2)
  {
      int i;
 
      i = 0;
      while (s2[i])
      {
          s1[i] = s2[i];
	  i++;
      }
      s1[i] = s2[i];
      return (s1);
  }
int verificar_ber(char *str)
{
	int i;
	int k;
	char *frase;

	i = 0;
	frase = malloc(5 * sizeof(char));
	ft_strcpy(frase,".ber");
	while(str[i] != '\0')
	{
		k = 0;
		while(str[i+k] == frase[k])
		{
			if(frase[k+1] == '\0')
			{
				free(frase);
				return (0);
			}
			k++;
		}
		i++;
	}
	free(frase);
	return(1);
}

int ver_erro(int x, int y, char *str,t_data *data)
{
	int erro;

	erro = 0;
	if(data->map.collect == 0 || data->map.exit != 1 || data->map.player_counter != 1)
		erro = 1;
	if(x == -1 || x == y)
		erro = 1;
	if((verificar_ber(str)) != 0)
		erro = 1;
	return(erro);
}

void atribuir_col_e_lin(t_data *data,int x,int y)
{
	data->map.col = x;
	data->map.lin = y;
}

int main(int ac, char **av)
{
	int fd_x;
	int fd_y;
	int y,x;
	t_data data;
	int fd;
	if(ac == 2)
	{
		data.mlx = mlx_init();
		fd_x = open(av[1],O_RDONLY);
		fd_y = open(av[1],O_RDONLY);
		y = funcao_y(fd_x);
		x = funcao_x(fd_y);
		close(fd_x);
		close(fd_y);
		atribuir_col_e_lin(&data,x,y);
		fd = open(av[1],O_RDONLY);
		get_map(&data,fd);
		ver_objetos(&data);
		get_imagens(&data);
		close(fd);
		if(ver_erro(x,y,av[1],&data) == 1)
		{
			ft_printf("Error\n");
			exit(0);
			return (0);
		}
		data.win = mlx_new_window(data.mlx,x*32,y*32,"so_long");
		mlx_hook(data.win,2,1,key_handler,&data);
		mlx_hook(data.win,17, 1L << 17,mouse_hook,NULL);
		render_map(&data);
		mlx_loop(data.mlx);
	}
	return 0;
}
