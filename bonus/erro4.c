/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erro4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:14:06 by marvin            #+#    #+#             */
/*   Updated: 2023/04/12 20:14:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	iniciar_line_y(int *fd, char *str, int *i)
{
	*fd = open(str, O_RDONLY);
	*i = contar_linha(str) - 1;
}

void	erro_line_y(int i)
{
	if (i == 1)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
}

void	verificar_line_y(char *s, int i, int *k)
{
	int	j;

	j = 0;
	while (s[j] != '\n' && s[j]
		&& ((!i || i == *k) && *k != 1))
	{
		if (s[j] != '1')
			*k = 1;
		j++;
	}
}

int	verificar_linha(char *str)
{
	int		fd;
	char	*s;
	int		retorno;

	retorno = 0;
	fd = open(str, O_RDONLY);
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		if (s[0] != '1')
			retorno = (1);
		free (s);
	}
	close (fd);
	return (retorno);
}

int	verificar_no_key(char *str)
{
	int		fd;
	char	*s;
	int		temp;

	temp = 0;
	fd = open(str, O_RDONLY);
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		if (check_no_key_func(s))
			temp = 1;
		free (s);
	}
	close (fd);
	return (temp);
}
