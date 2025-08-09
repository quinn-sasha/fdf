/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 09:16:18 by squinn            #+#    #+#             */
/*   Updated: 2025/08/09 09:42:46 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int destroy_window(t_data *data) {
  mlx_destroy_window(data->mlx, data->window);
  data->window = NULL;
  return (0);
}

int handle_keypress(int keysym, t_data *data) {
  if (keysym == XK_Escape)
    return destroy_window(data);
  return (0);
}
