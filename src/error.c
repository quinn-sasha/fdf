/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 16:53:25 by squinn            #+#    #+#             */
/*   Updated: 2025/08/03 17:04:25by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void handle_error(const char *message) {
  if (errno > 0)
    perror(message);
  else
    ft_putendl_fd(message, STDERR_FILENO);
  exit(EXIT_FAILURE);
}
