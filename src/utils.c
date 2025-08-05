/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:06:13 by squinn            #+#    #+#             */
/*   Updated: 2025/08/05 18:35:57 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point new_point(int x, int y, int z, uint32_t color);

void make_upper(unsigned int i, char *c) {
  (void)i;
  ft_toupper(*c);
}
