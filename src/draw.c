/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:06:33 by squinn            #+#    #+#             */
/*   Updated: 2025/08/09 14:59:44 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void set_pixel(t_image *img, int x, int y, uint32_t color) {
  int bytes_per_pixel = img->bits_per_pixel / 8;
  int offset = img->row_size * y + x * bytes_per_pixel;
  char *pixel_addr = img->address + offset;
  *(uint32_t *)pixel_addr = color;
}
