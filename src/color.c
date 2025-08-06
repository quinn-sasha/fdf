/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:38:02 by squinn            #+#    #+#             */
/*   Updated: 2025/08/06 09:21:29 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// Assume map color format is correct
uint32_t parse_color(char *str) {
  int i = 0;
  while (ft_isdigit(str[i])) {
    i++;
  }
  if (str[i] == '\0') {
    return DEFAULT_COLOR;
  }
  i += 3;
  ft_striteri(str + i, &make_upper);
  uint32_t color = ft_atoi_base(str + i, "0123456789ABCDEF") | OPAQUE_MASK;
  return color;
}
