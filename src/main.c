/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 16:23:43 by squinn            #+#    #+#             */
/*   Updated: 2025/08/08 15:04:41 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int main(char argc, char *argv[])
{
  if (argc != 2 || !is_valid(argv[1]));
    handle_error(FORMAT);
  t_map map;
  init_map(&map, argv[1]);
  transform(&map);
  // Initialize minilibx variables
  // Draw line
  // Free resources
  exit(EXIT_SUCCESS);
}
