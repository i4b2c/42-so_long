/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:50:38 by marvin            #+#    #+#             */
/*   Updated: 2023/04/05 16:21:23 by icaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	s = ft_calloc(1024, 1);
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

int	contar_linha(char *str)
{
	int		fd;
	char	*s;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		free (s);
		i++;
	}
	close(fd);
	return (i);
}

char	**replicar_map(char *av)
{
	char	*s;
	char	**str;
	int		k;
	int		fd;

	fd = open(av, O_RDONLY);
	str = malloc((contar_linha(av) + 1) * sizeof (char *));
	k = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		str[k] = ft_strtrim(s, "\n");
		str[k][ft_strlen(str[k])] = 0;
		free (s);
		k++;
	}
	str[k] = NULL;
	close (fd);
	return (str);
}

int	check_path_valid(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != 0)
		{
			if (str[i][j] == 'P' || str[i][j] == 'C'
				|| str[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	get_player(char **str, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != 0)
		{
			if (str[i][j] == 'P')
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

int	check_side_ff(char **str, int x, int y)
{
	if (str[y][x + 1] == '2')
		return (1);
	if (str[y][x - 1] == '2')
		return (1);
	if (str[y + 1][x] == '2')
		return (1);
	if (str[y - 1][x] == '2')
		return (1);
	return (0);
}

void	flood_fill(char **str, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	str[y][x] = '2';
	while (str[i])
	{
		j = 0;
		while (str[i][j] != 0 && str[i][j] != '\n')
		{
			if (str[i][j] != '1' && str[i][j] != '2')
			{
				if (check_side_ff(str, j, i))
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

void	free_path(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}

int	check_path(char *str)
{
	char	**s;
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	s = replicar_map(str);
	get_player(s, &x, &y);
	flood_fill(s, x, y);
	i = check_path_valid(s);
	free_path(s);
	return (i);
}

void check_P_E_C(char *str, int *P, int *E, int *C)
{
	int i;

	i = 0;
	while(str[i] && str[i] != '\n')
	{
		if(str[i] == 'P')
			(*P)++;
		else if(str[i] == 'E')
			(*E)++;
		else if(str[i] == 'C')
			(*C)++;
		i++;
	}
}

int check_dobro(int P, int E, int C)
{
	if (C == 0)
		return (0);
	if (P != 1)
		return (0);
	if (E != 1)
		return (0);
	return (1);
}

int verificar_dobro(char *str)
{
	int P;
	int E;
	int C;
	int fd;
	char *s;

	fd = open(str,O_RDONLY);
	P = 0;
	E = 0;
	C = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		check_P_E_C(s,&P,&E,&C);
		free (s);
	}
	if(!check_dobro(P,E,C))
		return (1);
	return (0);
}

int check_extra_word(char *str)
{
	int i;

	i = 0;
	while(str[i] && str[i] != '\n')
	{
		if(str[i] != '1' && str[i] != '0'
			&& str[i] != 'P' && str[i] != 'C'
			&& str[i] != 'E')
			return 1;
		i++;
	}
	return 0;
}

int check_extra_key(char *str)
{
	int fd;
	char *s;
	int temp;

	temp = 0;
	fd = open(str,O_RDONLY);
	while(1)
	{
		s = get_next_line(fd);
		if (!s)
			break;
		if (check_extra_word(s))
			temp = 1;
		free (s);
	}
	close(fd);
	return temp;
}

int	erro(char *str)
{
	int	i;

	i = 0;
	if (verificar_ber(str))
		i = 1;
	else if (verificar_x(str) || verificar_y(str))
		i = 1;
	else if (erro_vazio(str))
		i = 1;
	else if (extra(str))
		i = 1;
	else if (check_extra_key(str))
		i = 1;
	else if (verificar_linha(str))
		i = 1;
	else if (verificar_len_linha(str))
		i = 1;
	else if (verificar_dobro(str))
		i = 1;
	else if (check_path(str))
		i = 1;
	return (i);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		if (!erro(av[1]))
			iniciar_jogo(&data, av);
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
