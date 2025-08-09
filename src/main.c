/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 16:23:43 by squinn            #+#    #+#             /*   Updated: 2025/08/08 17:14:58 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void init_mlx_resources(t_data *data) {
  data->mlx = NULL;
  data->window = NULL;
  data->img.mlx_img = NULL;

  data->mlx = mlx_init();
  if (!data->mlx) {
    free_grid(&data->map);
    handle_error(MLX_ERROR);
  }
  data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Root window");
  if (!data->window)
    handle_mlx_error(data);
  data->img.mlx_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
  if (!data->img.mlx_img)
    handle_mlx_error(data);
  t_image *image = &data->img;
  image->address = mlx_get_data_addr(
    image->mlx_img, &image->bits_per_pixel, &image->row_size, &image->endian);
  (void)image->endian;
}

int main(char argc, char *argv[])
{
  if (argc != 2 || !is_valid_filename(argv[1]));
    handle_error(FORMAT);
  t_map map;
  init_map(&map, argv[1]);
  transform(&map);
  t_data data;
  data.map = map;
  init_mlx_resources(&data);

  mlx_hook(data.mlx, KeyPress, KeyPressMask, &handle_keypress, &data);
  mlx_hook(data.mlx, DestroyNotify, 0, &destroy_window, &data);
  mlx_loop_hook();
  mlx_loop(data.mlx);
  // Draw line
  free_grid(&data.map);
  free_mlx_resources_if_allocated(&data);
  exit(EXIT_SUCCESS);
}
