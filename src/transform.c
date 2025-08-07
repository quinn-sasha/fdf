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

void rotate_around_z_axis(t_map *map, int angle) {
  int row = 0;
  while (row < map->num_rows) {
    int col = 0;
    while (col < map->num_cols) {
      t_point *point = &(map->grid[row][col]);
      double x = map->grid[row][col].x;
      double y = map->grid[row][col].y;
      point->x = x * cos(angle) - y * sin(angle);
      point->y = x * sin(angle) + y * cos(angle);
      col++;
    }
    row++;
  }
}

void rotate_around_x_axis(t_map *map, int angle) {
  int row = 0;
  while (row < map->num_rows) {
    int col = 0;
    while (col < map->num_cols) {
      t_point *point = &(map->grid[row][col]);
      double y = map->grid[row][col].y;
      double z = map->grid[row][col].z;
      point->y = y * cos(angle) - z * sin(angle);
      point->z = y * sin(angle) + z * cos(angle);
      col++;
    }
    row++;
  }
}

void isometric_project(t_map *map) {
  rotate_around_z_axis(map, 45);
  rotate_around_x_axis(map, atan(sin(45)));
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

// Assume (x, y) is in the range of int size
void set_min_and_max_x_y(t_map *map) {
  map->min_x = INT_MAX;
  map->min_y = INT_MAX;
  map->max_x = INT_MIN;
  map->max_y = INT_MIN;

  int row = 0;
  while (row < map->num_rows) {
    int col = 0;
    while (col < map->num_cols) {
      t_point point = map->grid[row][col];
      map->min_x = ft_min(map->min_x, point.transformed_x);
      map->min_y = ft_min(map->min_y, point.transformed_y);
      map->max_x = ft_max(map->max_x, point.transformed_x);
      map->max_y = ft_max(map->max_y, point.transformed_y);
      col++;
    }
    row++;
  }
}

void translate(t_map* map, int dx, int dy) {
  int row = 0;
  while (row < map->num_rows) {
    int col = 0;
    while (col < map->num_cols) {
      t_point *point = &(map->grid[row][col]);
      point->transformed_x += dx;
      point->transformed_y += dy;
      col++;
    }
    row++;
  }
}

// Assume (min_x + max_x) and (min_y + max_y) don't overflow
void shift_map_to_center(t_map *map) {
  set_min_and_max_x_y(map);
  int mid_x = (map->min_x + map->max_x) / 2;
  int mid_y = (map->min_y + map->max_y) / 2;
  int x_offset = WIDTH / 2 - mid_x;
  int y_offset = HEIGHT / 2 - mid_y;
  translate(map, x_offset, y_offset);
}

void scale(t_map *map, int rate) {
  int row = 0;
  while (row < map->num_rows) {
    int col = 0;
    while (col < map->num_cols) {
      t_point *point = &(map->grid[row][col]);
      point->transformed_x *= rate;
      point->transformed_y *= rate;
      col++;
    }
    row++;
  }
}

void make_map_fit_on_display(t_map *map) {
  int map_width = map->max_x - map->min_x;
  int map_height = map->max_y - map->min_y;
  int x_scaling_rate = WIDTH / map_width;
  int y_scaling_rate = HEIGHT / map_height;
  int scaling_rate = ft_min(x_scaling_rate, y_scaling_rate);
  scale(map, scaling_rate);
}

void transform(t_map *map) {
  isometric_project(map);
  shift_map_to_center(map);
  make_map_fit_on_display(map);
}
