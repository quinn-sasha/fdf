#include "../include/fdf.h"

int main(int argc, char *argv[]) {
  (void)argc;
  t_map map;
  init_map(&map, argv[1]);
  transform(&map);
  printf("num_rows: %d, num_cols: %d\n", map.num_rows, map.num_cols);
  for (int row = 0; row < map.num_rows; row++) {
    for (int col = 0; col < map.num_cols; col++) {
      t_point point = map.grid[row][col];
      printf(
        "x: %d, y: %d\n",
        point.transformed_x, point.transformed_y);
    }
  }
}
