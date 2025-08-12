/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:44:11 by squinn            #+#    #+#             */
/*   Updated: 2025/08/12 11:44:13 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	isometric_project(t_map *map)
{
	double	angle1;
	double	angle2;

	angle1 = -(double)45 * (M_PI / 180);
	angle2 = atan(1.0 / sqrt(3.0));
	rotate_around_z_axis(map, angle1);
	rotate_around_x_axis(map, angle2);
}

// Assume (x, y) is in the range of int size
void	set_min_and_max_x_y(t_map *map)
{
	int		row;
	int		col;
	t_point	point;

	map->min_x = DBL_MAX;
	map->min_y = DBL_MAX;
	map->max_x = -DBL_MAX;
	map->max_y = -DBL_MAX;
	row = 0;
	while (row < map->num_rows)
	{
		col = 0;
		while (col < map->num_cols)
		{
			point = map->grid[row][col];
			map->min_x = double_min(map->min_x, point.x);
			map->min_y = double_min(map->min_y, point.y);
			map->max_x = double_max(map->max_x, point.x);
			map->max_y = double_max(map->max_y, point.y);
			col++;
		}
		row++;
	}
}

// Assume (min_x + max_x) and (min_y + max_y) don't overflow
void	shift_map_to_center(t_map *map)
{
	double	mid_x;
	double	mid_y;
	double	x_offset;
	double	y_offset;

	mid_x = (map->min_x + map->max_x) / 2;
	mid_y = (map->min_y + map->max_y) / 2;
	x_offset = WIDTH / 2 - mid_x;
	y_offset = HEIGHT / 2 - mid_y;
	translate(map, x_offset, y_offset);
}

void	make_map_fit_on_display(t_map *map)
{
	double	map_width;
	double	map_height;
	double	x_scaling_rate;
	double	y_scaling_rate;
	double	scaling_rate;

	map_width = map->max_x - map->min_x;
	map_height = map->max_y - map->min_y;
	x_scaling_rate = WIDTH / map_width;
	y_scaling_rate = HEIGHT / map_height;
	x_scaling_rate *= MARGIN;
	y_scaling_rate *= MARGIN;
	scaling_rate = double_min(x_scaling_rate, y_scaling_rate);
	scale(map, scaling_rate);
}

// Order should be rotate -> shift -> scale
void	transform(t_map *map)
{
	int		row;
	int		col;
	t_point	*point;

	isometric_project(map);
	set_min_and_max_x_y(map);
	make_map_fit_on_display(map);
	set_min_and_max_x_y(map);
	shift_map_to_center(map);
	row = 0;
	while (row < map->num_rows)
	{
		col = 0;
		while (col < map->num_cols)
		{
			point = &(map->grid[row][col]);
			point->transformed_x = (int)point->x;
			point->transformed_y = (int)point->y;
			point->transformed_z = (int)point->z;
			col++;
		}
		row++;
	}
}
