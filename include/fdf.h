/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 16:00:03 by squinn            #+#    #+#             */
/*   Updated: 2025/08/08 18:21:21 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include "../mlx_linux/mlx.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <math.h>
#include <float.h>

// display
# define WIDTH 1920
# define HEIGHT 1080
// Color
# define WHITE 0xFFFFFFFF
# define DEFAULT_COLOR WHITE
# define OPAQUE_MASK 0xFF000000

// Error messages
# define FORMAT "Usage: ./fdf filename.fdf"
# define MALLOC "malloc() failed"
# define MLX_ERROR "Minilibx library failed"


typedef struct s_point {
  double x;
  double y;
  double z;
  int transformed_x;
  int transformed_y;
  int transformed_z;
  uint32_t color;
} t_point;

typedef struct s_map {
  t_point **grid;
  int num_rows;
  int num_cols;
  double min_x;
  double min_y;
  double max_x;
  double max_y;
} t_map;

typedef struct s_image {
  void *mlx_img;
  char *address;
  int bits_per_pixel;
  int row_size;
  int endian;
} t_image;

typedef struct s_data {
  void *mlx;
  void *window;
  t_image img;
  t_map map;
} t_data;

// init_map.c
void set_num_rows_and_columns(t_map *map, const char *filename);
void allocate_grid(t_map *map);
void fill_one_row(t_map *map, int row, int fd);
void fill_grid(t_map *map, const char *filename);
void init_map(t_map *map, const char *filename);
// transform.c
void isometric_project(t_map *map);
void set_min_and_max_x_y(t_map *map);
void shift_map_to_center(t_map *map);
void make_map_fit_on_display(t_map *map);
void transform(t_map *map);
// transform2.c
void rotate_around_z_axis(t_map *map, double angle);
void rotate_around_x_axis(t_map *map, double angle);
void translate(t_map* map, double dx, double dy);
void scale(t_map *map, double rate);
// color.c
uint32_t parse_color(char *str);
// error.c
void handle_error(char *message);
void free_grid(t_map *map);
void free_mlx_resources_if_allocated(t_data *data);
void handle_mlx_error(t_data *data);
// utils.c
t_point new_point(double x, double y, double z, uint32_t color);
double double_min(double a, double b);
double double_max(double a, double b);
int is_valid_filename(char *filename);
// additional_libft.c
void make_upper(unsigned int i, char *c);
int count_num_cols(char *line);
void *free_words(char **words);

#endif
