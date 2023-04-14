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
	if (verificar_ber(str))
		return (1);
	else if (erro_vazio(str))
		return (1);
	else if (extra(str))
		return (1);
	else if (verificar_x(str) || verificar_y(str))
		return (1);
	else if (verificar_linha(str) || verificar_no_key(str))
		return (1);
	else if (verificar_len_linha(str))
		return (1);
	else if (verificar_dobro(str))
		return (1);
	else if (check_path(str))
		return (1);
	return (0);
}
