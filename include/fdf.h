/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 16:00:03 by squinn            #+#    #+#             */
/*   Updated: 2025/08/04 16:52:20 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <math.h>


// Error messages
# define FORMAT "Usage: ./fdf filename.fdf"


typedef struct s_point {
  int x;
  int y;
  int z;
  uint32_t color;
} t_point;

typedef struct s_map {
  t_point **grid;
  int num_rows;
  int num_cols;
} t_map;

typedef struct s_image {
  void *mlx_img;
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

// error.c
void handle_error(const char *message);
void free_grid(t_map *map);
void map_error(t_map *map, const char *message);


#endif
