/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erro_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:51:33 by marvin            #+#    #+#             */
/*   Updated: 2023/04/09 21:51:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	erro(char *str)
{
	int	i;

	i = 0;
	if (verificar_ber(str))
		i = 1;
	else if (erro_vazio(str))
		i = 1;
	else if (extra(str))
		i = 1;
	else if (verificar_x(str) || verificar_y(str))
		i = 1;
	else if (verificar_linha(str) || verificar_no_key(str))
		i = 1;
	else if (verificar_len_linha(str))
		i = 1;
	else if (verificar_dobro(str))
		i = 1;
	else if (check_path(str))
		i = 1;
	return (i);
}
