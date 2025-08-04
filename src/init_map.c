/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:56:19 by squinn            #+#    #+#             */
/*   Updated: 2025/08/04 13:27:12by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int count_num_cols(char *line) {
  int result;
  int i;

  result = 0;
  i = 0;
  while (line[i]) {
    if (line[i] == ' ') {
      i++;
      continue;
    }
    while (line[i] && line[i] != ' ') {
      i++;
    }
    result++;
  }
  return result;
}

/*
Assumption:
- get_next_line works without error
- Input file contains at least 1 line
*/
void set_num_rows_and_columns(t_map *map, const char *filename) {
  int fd = open(filename, O_RDONLY);
  char *line = get_next_line(fd);
  map->num_cols = count_num_cols(line);
  free(line);
  int num_rows = 1;
  while (TRUE) {
    line = get_next_line(fd);
    if (line == NULL)
      break;
    free(line);
    num_rows += 1;
  }
  map->num_rows = num_rows;
  close(fd);
}

void allocate_grid(t_map *map) {
  t_point **grid;
  grid = malloc(map->num_rows * sizeof(t_point*));
  if (grid == NULL) {
    // TODO: error message
    handle_error("");
  }
  int i;
  i = 0;
  while (i < map->num_rows) {
    grid[i] = malloc(map->num_cols * sizeof(t_point));
    if (grid[i] == NULL) {
      // TODO: error message
      map_error(map, "");
    }
    i++;
  }
  map->grid = grid;
}

t_map init_map(const char *filename) {
  t_map map;
  set_num_rows_and_columns(&map, filename);
  allocate_grid(&map);
  // Fill grid
  // Return grid
  return map;
}
