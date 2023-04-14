/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erro5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:20:28 by marvin            #+#    #+#             */
/*   Updated: 2023/04/13 23:20:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_no_key_func(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '1' && str[i] != '0'
			&& str[i] != 'P' && str[i] != 'C'
			&& str[i] != 'E' && str[i] != 'N')
			return (1);
		i++;
	}
	return (0);
}
