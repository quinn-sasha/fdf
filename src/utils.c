/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:06:13 by squinn            #+#    #+#             */
/*   Updated: 2025/08/06 10:39:46 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point new_point(int x, int y, int z, uint32_t color) {
  t_point point;
  point.x = x;
  point.y = y;
  point.z = z;
  point.transformed_x = -1;
  point.transformed_y = -1;
  point.color = color;
  return point;
}

void make_upper(unsigned int i, char *c) {
  (void)i;
  ft_toupper(*c);
}

int count_num_cols(char *line) {
  int result;
  int i;

  result = 0;
  i = 0;
  while (line[i]) {
    if (line[i] == ' ') {
      i++;
      continue;
    }
    while (line[i] != ' ') {
      i++;
    }
    result++;
  }
  return result;
}
