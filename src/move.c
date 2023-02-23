/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:35:27 by slord             #+#    #+#             */
/*   Updated: 2023/02/23 13:03:11 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	player_move(int keycode, t_data *data)
{
	
		if (keycode == 123)
			data->dir_x -= 5;
		else if (keycode == 124)
			data->dir_x += 5;
		if (data->dir_x > 360)
			data->dir_x = 5;
		else if (data->dir_x < 0)
			data->dir_x = 360 - 5;
		raycasting(data);
	return (0);
}