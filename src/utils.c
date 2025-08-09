/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:06:13 by squinn            #+#    #+#             */
/*   Updated: 2025/08/09 16:10:37 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point new_point(double x, double y, double z, uint32_t color) {
  t_point point;
  point.x = x;
  point.y = y;
  point.z = z;
  point.transformed_x = -1;
  point.transformed_y = -1;
  point.transformed_z = -1;
  point.color = color;
  return point;
}

uint32_t get_color_gradient(t_point a, t_point b, int position, int is_gentle) {
  if (a.color == b.color)
    return a.color;
  int ratio;
  if (is_gentle)
    ratio = (position - a.x) / (b.x - a.x);
  else
    ratio = (position - a.y) / (b.y - a.y);
  uint32_t color = a.color + ratio * (b.color - a.color);
  return color;
}

// dx cannot be 0
int get_sign(int x) {
  if (x > 0)
    return 1;
  if (x < 0)
    return -1;
  return 0;
}

double double_min(double a, double b) {
  if (a < b)
    return (a);
  return (b);
}

double double_max(double a, double b) {
  if (a > b)
    return (a);
  return (b);
}
