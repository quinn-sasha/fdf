#include <stdio.h>
#include "../include/fdf.h"

int main(int argc, char *argv[]) {
  (void)argc;
  t_map map;
  set_num_rows_and_columns(&map, argv[1]);
  printf("Number of rows: %d\n", map.num_rows);
  printf("Number of cols: %d\n", map.num_cols);
}
