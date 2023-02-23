/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:38:11 by slord             #+#    #+#             */
/*   Updated: 2023/02/23 13:22:44 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clear_img_array(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIN_HEIGHT * WIN_WIDTH * 4)
	{
		data->screen_data[i] = 0;
		i++;
	}
}

void	draw_ray(t_ray *ray, t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = ray->position;
	y = (WIN_HEIGHT / 2) - (ray->wall_h / 2);
	while (ray->wall_h > 0)
	{
		data->screen_data[x * 4 + 4 * WIN_WIDTH * y] = 100;
		y++;
		ray->wall_h--;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img.pointer, 0, 0);
	//clear_img_array(data);
}

void	ray_size(t_ray *ray, t_data *data)
{
	ray->distance = sqrt(pow(data->player_x - ray->x, 2) + \
	pow(data->player_y - ray->y, 2));
	ray->distance = ray->distance * cos(ray->angle * (PI / 180) - \
	data->dir_x * (PI / 180));
	ray->wall_h = floor((WIN_HEIGHT / 2) / ray->distance);
	draw_ray(ray, data);
}


void	raycasting(t_data *data)
{
	int	i;
	t_ray ray;
		int     bpp;
int     size_line;
int     endian;

	i = 0;
	if (data->img.pointer)
		mlx_clear_window(data->mlx, data->window);
	if (data->img.pointer)
		free(data->img.pointer);
	data->img.pointer = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->screen_data =  mlx_get_data_addr(data->img.pointer, &bpp, &size_line, &endian);
	ray.angle = data->dir_x - (VISION / 2);
	while (i < WIN_WIDTH)
	{
		ray.position = i;
		ray.x = data->player_x;
		ray.y = data->player_y;
		ray.cos = cos(ray.angle * (PI / 180)) / (double) 500;
		ray.sin = sin(ray.angle * (PI / 180)) / (double) 500;
		while (data->map[(int)floor(ray.y)][(int) floor(ray.x)] == '0')
		{
			ray.x += ray.cos;
			ray.y += ray.sin;
		}
		ray_size(&ray, data);
		ray.angle += (double) VISION / WIN_WIDTH;
		i++;
	}
}
