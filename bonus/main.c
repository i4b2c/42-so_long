/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:50:38 by marvin            #+#    #+#             */
/*   Updated: 2023/04/05 16:22:18 by icaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	verificar_len_linha(char *str)
{
	int		fd;
	char	*s;
	int		len;

	len = 0;
	fd = open(str, O_RDONLY);
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		if (len && len != ft_strlen(s))
			return (1);
		len = ft_strlen(s);
		free (s);
	}
	close (fd);
	return (0);
}

int	extra(char *str)
{
	int		fd;
	char	*s;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	s = ft_calloc(1024,1);
	read(fd, s, 1024);
	while (s[i])
		i++;
	if (s[i - 1] == '\n')
	{
		free (s);
		close (fd);
		return (0);
	}
	free (s);
	close (fd);
	return (1);
}

int contar_linha(char *str)
{
	int fd;
	char *s;
	int i;

	i = 0;
	fd = open(str,O_RDONLY);
	while(1)
	{
		s = get_next_line(fd);
		if(!s)
			break;
		free(s);
		i++;
	}
	return (i);
}

char  **replicar_map(char *av)
{
	char	*s;
	char **str;
	int		k;
	int fd;

	fd = open(av,O_RDONLY);
	str = malloc((contar_linha(av)+1) * sizeof (char *));
	k = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		str[k] = ft_strtrim(s, "\n");
		str[k][ft_strlen(str[k])] = 0;
		free(s);
		k++;
	}
	str[k] = NULL;
	close(fd);
	return str;
}

int check_path_valid(char **str)
{
	int i;
	int j;
	i = 0;
	while(str[i])
	{
		j = 0;
		while(str[i][j] != 0)
		{
			if(str[i][j] == 'P' || str[i][j] == 'C'
				|| str[i][j] == 'E')
				return 1;
			j++;
		}
		i++;
	}
	return 0;
}

void get_player(char **str, int *x, int *y)
{
	int i;
	int j;

	i = 0;
	while(str[i])
	{
		j = 0;
		while(str[i][j] != 0)
		{
			if(str[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int check_side_ff(char **str, int x, int y)
{
	if(str[y][x+1] == '2')
		return 1;
	if(str[y][x-1] == '2')
		return 1;
	if(str[y+1][x] == '2')
		return 1;
	if(str[y-1][x] == '2')
		return 1;
	return 0;
}

void flood_fill(char **str, int x, int y)
{
	int i;
	int j;

	i = 0;
	str[y][x] = '2';
	while(str[i])
	{
		j = 0;
		while(str[i][j] != 0 && str[i][j] != '\n')
		{
			if(str[i][j] != '1' && str[i][j] != '2')
			{
				if(check_side_ff(str,j,i))
				{
					str[i][j] = '2';
					i = 0;
					j = 0;
				}
			}
			j++;
		}
		i++;
	}
}

void free_path(char **str)
{
	int i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int check_path(char *str)
{
	char **s;
	int i;
	int x;
	int y;

	x = 0;
	y = 0;
	s = replicar_map(str);
	get_player(s,&x,&y);
	flood_fill(s,x,y);
	i = check_path_valid(s);
	free_path(s);
	return (i);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		if (erro_vazio(av[1]) == 0
			&& verificar_linha(av[1]) == 0
			&& verificar_len_linha(av[1]) == 0
			&& verificar_ber(av[1]) == 0
			&& check_path(av[1]) == 0
			&& extra(av[1]) == 0)
			iniciar_jogo(&data, av);
		else
			write(1, "Error\n", 6);
	}
	return (0);
}
