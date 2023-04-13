/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erro1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:13:11 by marvin            #+#    #+#             */
/*   Updated: 2023/04/12 20:13:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	check_dobro(int p, int e, int c)
{
	if (c == 0)
		return (0);
	if (p != 1)
		return (0);
	if (e != 1)
		return (0);
	return (1);
}

int	verificar_dobro(char *str)
{
	int		p;
	int		e;
	int		c;
	int		fd;
	char	*s;

	fd = open(str, O_RDONLY);
	p = 0;
	e = 0;
	c = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		check_p_e_c(s, &p, &e, &c);
		free (s);
	}
	if (!check_dobro(p, e, c))
		return (1);
	return (0);
}

int	check_extra_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '1' && str[i] != '0'
			&& str[i] != 'P' && str[i] != 'C'
			&& str[i] != 'E')
			return (1);
		i++;
	}
	return (0);
}

int	check_extra_key(char *str)
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
		if (check_extra_word(s))
			temp = 1;
		free (s);
	}
	close (fd);
	return (temp);
}

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
