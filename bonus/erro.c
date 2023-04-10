/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erro.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:37:53 by marvin            #+#    #+#             */
/*   Updated: 2023/02/28 13:37:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	square_map(char **str)
{
	int	x;
	int	y;

	get_x_y(&x, &y, str);
	if (x == y)
		return (1);
	return (0);
}

int	erro_vazio(char *str)
{
	int		fd;
	char	*s;
	int		i;

	i = 0;
	s = malloc(1);
	fd = open(str, O_RDONLY);
	read (fd, s, 1);
	if (!s[0] || s[0] != '1')
		i = 1;
	else
		i = 0;
	free (s);
	close (fd);
	return (i);
}

int	verificar_ber(char *str)
{
	int		i;
	int		k;
	char	*frase;

	i = 0;
	frase = malloc(5 * sizeof(char));
	ft_strcpy(frase, ".ber");
	while (str[i] != '\0')
	{
		k = 0;
		while (str[i + k] == frase[k])
		{
			if (frase[k + 1] == '\0')
			{
				free(frase);
				return (0);
			}
			k++;
		}
		i++;
	}
	free (frase);
	return (1);
}

int	verificar_x(char *str)
{
	int		i;
	int		temp;
	char	*s;
	int		fd;
	int		temp2;

	fd = open(str, O_RDONLY);
	temp = 0;
	i = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		temp2 = ft_strlen(s);
		if (s[0] != '1'
			|| s[temp2 - 2] != '1')
			temp = 1;
		free (s);
		i++;
	}
	close (fd);
	return (temp);
}

void iniciar_line_y(int *fd, char *str, int *temp2)
{
	*fd = open(str, O_RDONLY);
	*temp2 = contar_linha(str) - 1;
}

void erro_line_y(int temp2)
{
	if (temp2 == 1)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
}

void verificar_line_y(char *s, int i ,int *temp2)
{
	int j;

	j = 0;
	while (s[j] != '\n' && s[j]
		&& ((!i || i == *temp2) && *temp2 != 1))
		{
			if (s[j] != '1')
				*temp2 = 1;
			j++;
		}
}

int	verificar_y(char *str)
{
	int		fd;
	char	*s;
	int		i;
	int		temp2;

	i = 0;
	iniciar_line_y(&fd,str,&temp2);
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		verificar_line_y(s,i,&temp2);
		i++;
		free (s);
	}
	erro_line_y(temp2);
	return (0);
}
