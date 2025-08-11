#include "../include/fdf.h"

int main(int argc, char *argv[]) {
  (void)argc;
  char *color_info = argv[1];
  uint32_t color = parse_color(color_info);
  printf("color: %8X\n", color);
}
