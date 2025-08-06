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

/*
Assumption:
- get_next_line works without error
- Map format is correct
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
  if (grid == NULL)
    handle_error(MALLOC);
  int row;
  row = 0;
  while (row < map->num_rows) {
    grid[row] = malloc(map->num_cols * sizeof(t_point));
    if (grid[row] == NULL)
      map_error(map, MALLOC);
    row++;
  }
  map->grid = grid;
}

/*
Assumption:
- get_next_line() works without error
- ft_split() works without error
*/
void fill_one_row(t_map *map, int row, int fd) {
  char *line = get_next_line(fd);
  char **words = ft_split(line, ' ');
  free(line);
  int col = 0;
  while (col < map->num_cols) {
    int z = ft_atoi(words[col]);
    uint32_t color = parse_color(words[col]);
    map->grid[row][col] = new_point(col, row, z, color);
    col++;
  }
  free_words(words);
}

void fill_grid(t_map *map, const char *filename) {
  int fd = open(filename, O_RDONLY);
  int row = 0;
  while (row < map->num_rows) {
    fill_one_row(map, row, fd);
    row++;
  }
  close(fd);
}

void init_map(t_map *map, const char *filename) {
  set_num_rows_and_columns(map, filename);
  allocate_grid(map);
  fill_grid(map, filename);
}
