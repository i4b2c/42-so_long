/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erro_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:57:34 by icaldas           #+#    #+#             */
/*   Updated: 2023/03/28 13:46:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
