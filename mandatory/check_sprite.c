/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:17:15 by marvin            #+#    #+#             */
/*   Updated: 2023/04/12 20:17:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check(t_data *data, int x, int y, int num)
{
	if (num == 1)
	{
		if (data->map.map[x][y - 1] == '0')
			return (1);
	}
	else if (num == 2)
	{
		if (data->map.map[x][y + 1] == '0')
			return (1);
	}
	else if (num == 3)
	{
		if (data->map.map[x - 1][y] == '0')
			return (1);
	}
	else if (num == 4)
	{
		if (data->map.map[x + 1][y] == '0')
			return (1);
	}
	return (0);
}
