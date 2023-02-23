/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:06:27 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/23 13:20:51 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	screen(char *img_data, int line_size)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < WIN_HEIGHT)
	{
		while (x < WIN_WIDTH)
		{
			if (y <  WIN_HEIGHT / 2)
				img_data[x * 4 + 4 * (line_size / 4) * y] = 0x000080;
			else
				img_data[x * 4 + 4 * (line_size / 4) * y + 1] = 100;
			x++;
		}
		x = 0;
		y++;	
	}
}
void init_data(t_data *data)
{
	char *test1 = "111111111111";
	char *test2 = "100001000001";
	char *test3 = "110000000001";
	char *test4 = "100100000001";
	char *test5 = "111111111111";

	data->map = malloc(sizeof(char *) * 5);

	
	
			data->map[0]= ft_strdup(test1);
			data->map[1]= ft_strdup(test2);
			data->map[2]= ft_strdup(test3);
			data->map[3]= ft_strdup(test4);
			data->map[4]= ft_strdup(test5);
	

	
	data->dir_x =180;
	//data->dir_y = -1;
	data->player_x = 4;
	data->player_y = 2;
	
	
}
void	free_struct (t_data *data)
{
	
	free(data->map);
}

int	main(int argc, char **argv)
{
	
	(void)argc;
	(void)argv;
	t_data data;
	data.mlx = mlx_init();
	init_data(&data);
	data.window = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	//screen(data.screen_data, size_line);
	raycasting(&data);
	mlx_hook(data.window, 2, 0, player_move, &data);
	mlx_loop(data.mlx);

}
 