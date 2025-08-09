/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:06:33 by squinn            #+#    #+#             */
/*   Updated: 2025/08/09 17:48:25 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void set_pixel(int x, int y, t_image *img,  uint32_t color) {
  int bytes_per_pixel = img->bits_per_pixel / 8;
  int offset = img->row_size * y + x * bytes_per_pixel;
  char *pixel_addr = img->address + offset;
  *(uint32_t *)pixel_addr = color;
}

void draw_gentle_line(t_point a, t_point b, t_image *img) {
  int dx = b.x - a.x;
  int dy = b.y - a.y;
  int discriminant = 2 * ft_abs(dy) - ft_abs(dx);

  set_pixel(a.x, a.y, img, a.color);
  int x = a.x;
  int y = a.y;
  int i = 0;
  while (i < ft_abs(dx)) {
    i++;
    x += get_direction(dx);
    uint32_t color = get_color_gradient(a, b, x, TRUE);
    if (discriminant < 0) {
      set_pixel(x, y, img, color);
      discriminant += 2 * ft_abs(dy);
      continue;
    }
    y += get_direction(dy);
    set_pixel(x, y, img, color);
    discriminant += 2 * ft_abs(dy) - 2 * ft_abs(dx);
  }
}

void draw_steep_line(t_point a, t_point b, t_image *img) {
  int dx = b.x - a.x;
  int dy = b.y - a.y;
  int discriminant = ft_abs(dy) - 2 * ft_abs(dx);

  set_pixel(a.x, a.y, img, a.color);
  int x = a.x;
  int y = a.y;
  int i = 0;
  while (i < ft_abs(dy)) {
    i++;
    y += get_direction(dy);
    uint32_t color = get_color_gradient(a, b, y, FALSE);
    if (discriminant > 0) {
      set_pixel(x, y, img, color);
      discriminant += -2 * ft_abs(dx);
      continue;
    }
    x += get_direction(dx);
    set_pixel(x, y, img, color);
    discriminant += 2 * ft_abs(dy) - 2 * ft_abs(dx);
  }
}

void draw_line(t_point a, t_point b, t_image *img) {
  int dx = b.x - a.x;
  int dy = b.y - a.y;

  if (ft_abs(dx) > ft_abs(dy))
    return draw_gentle_line(a, b, img);
  return draw_steep_line(a, b, img);
}

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
