/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:15:29 by squinn            #+#    #+#             */
/*   Updated: 2025/08/08 14:17:39 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void rotate_around_z_axis(t_map *map, double angle) {
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

void rotate_around_x_axis(t_map *map, double angle) {
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

void translate(t_map* map, double dx, double dy) {
  int row = 0;
  while (row < map->num_rows) {
    int col = 0;
    while (col < map->num_cols) {
      t_point *point = &(map->grid[row][col]);
      point->x += dx;
      point->y += dy;
      col++;
    }
    row++;
  }
}

void scale(t_map *map, double rate) {
  int row = 0;
  while (row < map->num_rows) {
    int col = 0;
    while (col < map->num_cols) {
      t_point *point = &(map->grid[row][col]);
      point->x *= rate;
      point->y *= rate;
      col++;
    }
    row++;
  }
}
