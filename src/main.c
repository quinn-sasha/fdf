/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:18:10 by squinn            #+#    #+#             */
/*   Updated: 2025/08/11 14:23:54 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_mlx_resources(t_data *data)
{
	t_image	*image;

	data->mlx = NULL;
	data->window = NULL;
	data->img.mlx_img = NULL;
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free_grid(&data->map);
		handle_error(MLX_ERROR);
	}
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Root window");
	if (!data->window)
		handle_mlx_error(data);
	data->img.mlx_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img.mlx_img)
		handle_mlx_error(data);
	image = &data->img;
	image->address = mlx_get_data_addr(image->mlx_img, &image->bits_per_pixel,
			&image->row_size, &image->endian);
	(void)image->endian;
}

int	main(int argc, char *argv[])
{
	t_map	map;
	t_data	data;

	if (argc != 2 || !is_valid_filename(argv[1]))
		handle_error(FORMAT);
	init_map(&map, argv[1]);
	transform(&map);
	data.map = map;
	init_mlx_resources(&data);
	mlx_hook(data.window, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.window, DestroyNotify, 0, &destroy_window, &data);
	mlx_loop_hook(data.mlx, &draw_map, &data);
	mlx_loop(data.mlx);
	free_grid(&data.map);
	free_mlx_resources_if_allocated(&data);
	exit(EXIT_SUCCESS);
}
