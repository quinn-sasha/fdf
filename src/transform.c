/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:13:11 by squinn            #+#    #+#             *//*   Updated: 2025/08/07 11:58:14 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void isometric_project(t_map *map) {
  double angle1 = (double)45 * (M_PI / 180);
  double angle2 = atan(1.0 / sqrt(3.0));
  rotate_around_z_axis(map, angle1);
  rotate_around_x_axis(map, angle2);
}

// Assume (x, y) is in the range of int size
void set_min_and_max_x_y(t_map *map) {
  map->min_x = DBL_MAX;
  map->min_y = DBL_MAX;
  map->max_x = -DBL_MAX;
  map->max_y = -DBL_MAX;

  int row = 0;
  while (row < map->num_rows) {
    int col = 0;
    while (col < map->num_cols) {
      t_point point = map->grid[row][col];
      map->min_x = double_min(map->min_x, point.x);
      map->min_y = double_min(map->min_y, point.y);
      map->max_x = double_max(map->max_x, point.x);
      map->max_y = double_max(map->max_y, point.y);
      col++;
    }
    row++;
  }
}

// Assume (min_x + max_x) and (min_y + max_y) don't overflow
void shift_map_to_center(t_map *map) {
  double mid_x = (map->min_x + map->max_x) / 2;
  double mid_y = (map->min_y + map->max_y) / 2;
  double x_offset = WIDTH / 2 - mid_x;
  double y_offset = HEIGHT / 2 - mid_y;
  translate(map, x_offset, y_offset);
}

void make_map_fit_on_display(t_map *map) {
  double map_width = map->max_x - map->min_x;
  double map_height = map->max_y - map->min_y;
  double x_scaling_rate = WIDTH / map_width;
  double y_scaling_rate = HEIGHT / map_height;
  double scaling_rate = double_min(x_scaling_rate, y_scaling_rate);
  scale(map, scaling_rate);
}

// Order should be rotate -> shift -> scale
void transform(t_map *map) {
  isometric_project(map);
  set_min_and_max_x_y(map);
  make_map_fit_on_display(map);
  set_min_and_max_x_y(map);
  shift_map_to_center(map);

  int row = 0;
  while (row < map->num_rows) {
    int col = 0;
    while (col < map->num_cols) {
      t_point *point = &(map->grid[row][col]);
      point->transformed_x = (int)point->x;
      point->transformed_y = (int)point->y;
      point->transformed_z = (int)point->z;
      col++;
    }
    row++;
  }
}
