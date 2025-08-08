#include "../include/fdf.h"

int main(int argc, char *argv[]) {
  (void)argc;
  t_map map;
  init_map(&map, argv[1]);
  for (int row = 0; row < map.num_rows; row++) {
    printf("\n");
    for (int col = 0; col < map.num_cols; col++) {
        int x = map.grid[row][col].x;
        int y = map.grid[row][col].y;
        int z = map.grid[row][col].z;
        printf("x: %d, y: %d, z: %d | ", x, y, z);
    }
  }
}
