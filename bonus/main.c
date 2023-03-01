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

#include "../include/so_long_bonus.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		if (erro_vazio(av[1]) == 0)
			iniciar_jogo(&data, av);
		else
			ft_printf("Error\n");
	}
	return (0);
}
