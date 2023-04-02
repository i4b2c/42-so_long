/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:50:38 by marvin            #+#    #+#             */
/*   Updated: 2023/02/28 13:50:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int verificar_len_linha(char *str)
{
	int fd;
	char *s;
	int len;

	len = 0;
	fd = open(str,O_RDONLY);
	while(1)
	{
		s = get_next_line(fd);
		if(!s)
			break;
		if(len && len != ft_strlen(s))
			return 1;
		len = ft_strlen(s);
		free(s);
	}
	close(fd);
	return 0;
}

int extra(char *str)
{
	int fd;
	char s[1024];

	fd = open(str,O_RDONLY);
	read(fd,s,1024);
	int i = 0;
	while(s[i])
		i++;
	if(s[i-1] == '\n')
	{
		close(fd);
		return 0;
	}
	close(fd);
	return 1;
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
			&& extra(av[1]) == 0)
			iniciar_jogo(&data, av);
		else
			write(1,"Error\n",6);
	}
	else
		write(1,"Error\n",6);
	return (0);
}
