/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:13:11 by squinn            #+#    #+#             */
/*   Updated: 2025/08/07 11:25:00 by squinn           ###   ########.fr       */
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
  // R(arctan(-1/sqrt(2)))
}

void transform(t_map *map) {
  isometric_project(map);
  // 平行移動
  // ズーム
}
