/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:08:17 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/23 12:34:09 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include<stdio.h>
# include "mlx/mlx.h"
# include <math.h>
# include "libft/libft.h"
# define WIN_WIDTH	500
# define WIN_HEIGHT	500
# define PI	3.14159265
# define VISION 80
// #include<>
// #include<>
// #include<>
// #include<>

typedef struct s_img{
	void	*pointer;
	int	height;
	int	width;
}	t_img;

typedef struct s_data{
	void *mlx;
	void *window;
	char **map;
	double player_x;
	double player_y;
	double dir_x;
	//double dir_y;
	char *screen_data;
	t_img img;
	
}	t_data;

typedef struct s_ray{
	int		position;
	double	x;
	double	y;
	double	cos;
	double	sin;
	double	angle;
	double	distance;
	int		wall_h;
}	t_ray;

// raycasting
void	raycasting(t_data *data);

//mouvements
int	player_move(int keycode, t_data *data);
#endif