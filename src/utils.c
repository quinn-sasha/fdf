/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:06:13 by squinn            #+#    #+#             */
/*   Updated: 2025/08/08 14:36:07 by squinn           ###   ########.fr       */
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
