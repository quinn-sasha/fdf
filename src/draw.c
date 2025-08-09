/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:06:33 by squinn            #+#    #+#             */
/*   Updated: 2025/08/09 16:34:54 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void set_pixel(t_image *img, int x, int y, uint32_t color) {
  int bytes_per_pixel = img->bits_per_pixel / 8;
  int offset = img->row_size * y + x * bytes_per_pixel;
  char *pixel_addr = img->address + offset;
  *(uint32_t *)pixel_addr = color;
}

void draw_line(t_point a, t_point b, t_image *img);

void draw_map(t_data *data) {
  int row = 0;
  while (data->map.num_rows) {
    int col = 0;
    while (col < data->map.num_cols) {
      t_point **grid = data->map.grid;
      int last_col = data->map.num_cols - 1;
      if (col < last_col) {
        draw_line(grid[row][col], grid[row][col + 1], &data->img);
      }
      int last_row = data->map.num_rows - 1;
      if (row < last_row) {
        draw_line(grid[row][col], grid[row + 1][col], &data->img);
      }
      col++;
    }
    row++;
  }
}
