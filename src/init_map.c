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

t_point **allocate_grid(int num_rows, int num_cols) {
  t_point **grid;
  grid = malloc(num_rows * sizeof(t_point*));
  if (grid == NULL) {
    
  }
  int i;
  i = 0;
  while (i < num_cols) {
    grid[i] = malloc(num_cols * sizeof(t_point));
    i++;
  }
  return grid;
}

t_map init_map(const char *filename) {
  t_map map;
  set_num_rows_and_columns(&map, filename);
  map.grid = allocate_grid();

  // Fill grid
  // Return grid
  return map;
}
