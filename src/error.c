/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 16:53:25 by squinn            #+#    #+#             */
/*   Updated: 2025/08/03 17:04:25by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int is_valid_filename(char *filename) {
  int len = ft_strlen(filename);
  if (len <= 4) {
    return (FALSE);
  }
  filename += len - 4;
  return (ft_strncmp(filename, ".fdf", 4) == 0);
}

void handle_error(char *message) {
  if (errno > 0)
    perror("FdF");
  else
    ft_putendl_fd(message, STDERR_FILENO);
  exit(EXIT_FAILURE);
}

void free_grid(t_map *map) {
  int i;
  i = 0;
  while (i < map->num_rows) {
    free(map->grid[i]);
    i++;
  }
  free(map->grid);
}

void free_mlx_resources_if_allocated(t_data *data) {
  if (data->img.mlx_img) {
    mlx_destroy_image(data->mlx, data->img.mlx_img);
  }
  if (data->window) {
    mlx_destroy_window(data->mlx, data->window);
  }
  mlx_destroy_display(data->mlx);
  free(data->mlx);
}

void handle_mlx_error(t_data *data) {
  free_grid(&data->map);
  free_mlx_resources_if_allocated(data);
  handle_error(MLX_ERROR);
}
