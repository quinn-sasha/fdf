/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:06:33 by squinn            #+#    #+#             */
/*   Updated: 2025/08/09 20:31:08 by squinn           ###   ########.fr       */
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
  int discriminant = 2 * ft_abs(a.dy) - ft_abs(a.dx);

  set_pixel(a.transformed_x, a.transformed_y, img, a.color);
  int x = a.transformed_x;
  int y = a.transformed_y;
  int i = 0;
  while (i < ft_abs(a.dx)) {
    i++;
    x += get_direction(a.dx);
    uint32_t color = get_color_gradient(a, b, x, TRUE);
    if (discriminant < 0) {
      set_pixel(x, y, img, color);
      discriminant += 2 * ft_abs(a.dy);
      continue;
    }
    y += get_direction(a.dy);
    set_pixel(x, y, img, color);
    discriminant += 2 * ft_abs(a.dy) - 2 * ft_abs(a.dx);
  }
}

void draw_steep_line(t_point a, t_point b, t_image *img) {
  int discriminant = ft_abs(a.dy) - 2 * ft_abs(a.dx);

  set_pixel(a.transformed_x, a.transformed_y, img, a.color);
  int x = a.transformed_x;
  int y = a.transformed_y;
  int i = 0;
  while (i < ft_abs(a.dy)) {
    i++;
    y += get_direction(a.dy);
    uint32_t color = get_color_gradient(a, b, y, FALSE);
    if (discriminant > 0) {
      set_pixel(x, y, img, color);
      discriminant += -2 * ft_abs(a.dx);
      continue;
    }
    x += get_direction(a.dx);
    set_pixel(x, y, img, color);
    discriminant += 2 * ft_abs(a.dy) - 2 * ft_abs(a.dx);
  }
}

void draw_line(t_point a, t_point b, t_image *img) {
  a.dx = b.transformed_x - a.transformed_x;
  a.dy = b.transformed_y - a.transformed_x;

  if (ft_abs(a.dx) > ft_abs(a.dy))
    return draw_gentle_line(a, b, img);
  return draw_steep_line(a, b, img);
}

int draw_map(t_data *data) {
  if (data->window == NULL)
    return (FAILED);
  t_point **grid = data->map.grid;
  int row = 0;
  while (row < data->map.num_rows) {
    int col = 0;
    while (col < data->map.num_cols) {
      if (col < data->map.num_cols - 1) {
        draw_line(grid[row][col], grid[row][col + 1], &data->img);
      }
      if (row < data->map.num_rows - 1) {
        draw_line(grid[row][col], grid[row + 1][col], &data->img);
      }
      col++;
    }
    row++;
  }
  return (SUCESS);
}
