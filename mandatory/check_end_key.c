/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:37:25 by marvin            #+#    #+#             */
/*   Updated: 2023/02/28 13:37:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	act_a(t_data *data)
{
	if (data->map.map[data->map.y][data->map.x - 1] == 'E'
		&& data->map.collect == 0)
		return (1);
	return (0);
}

int	act_d(t_data *data)
{
	if (data->map.map[data->map.y][data->map.x + 1] == 'E'
		&& data->map.collect == 0)
		return (1);
	return (0);
}

int	act_w(t_data *data)
{
	if (data->map.map[data->map.y - 1][data->map.x] == 'E'
		&& data->map.collect == 0)
		return (1);
	return (0);
}

int	act_s(t_data *data)
{
	if (data->map.map[data->map.y + 1][data->map.x] == 'E'
		&& data->map.collect == 0)
		return (1);
	return (0);
}
