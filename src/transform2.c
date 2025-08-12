/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:15:29 by squinn            #+#    #+#             */
/*   Updated: 2025/08/08 14:17:39 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate_around_z_axis(t_map *map, double angle)
{
	int		row;
	int		col;
	t_point	*point;
	double	x;
	double	y;

	row = 0;
	while (row < map->num_rows)
	{
		col = 0;
		while (col < map->num_cols)
		{
			point = &(map->grid[row][col]);
			x = map->grid[row][col].x;
			y = map->grid[row][col].y;
			point->x = x * cos(angle) - y * sin(angle);
			point->y = x * sin(angle) + y * cos(angle);
			col++;
		}
		row++;
	}
}

void	rotate_around_x_axis(t_map *map, double angle)
{
	int		row;
	int		col;
	t_point	*point;
	double	y;
	double	z;

	row = 0;
	while (row < map->num_rows)
	{
		col = 0;
		while (col < map->num_cols)
		{
			point = &(map->grid[row][col]);
			y = map->grid[row][col].y;
			z = map->grid[row][col].z;
			point->y = y * cos(angle) - z * sin(angle);
			point->z = y * sin(angle) + z * cos(angle);
			col++;
		}
		row++;
	}
}

void	translate(t_map *map, double dx, double dy)
{
	int		row;
	int		col;
	t_point	*point;

	row = 0;
	while (row < map->num_rows)
	{
		col = 0;
		while (col < map->num_cols)
		{
			point = &(map->grid[row][col]);
			point->x += dx;
			point->y += dy;
			col++;
		}
		row++;
	}
}

void	scale(t_map *map, double rate)
{
	int		row;
	int		col;
	t_point	*point;

	row = 0;
	while (row < map->num_rows)
	{
		col = 0;
		while (col < map->num_cols)
		{
			point = &(map->grid[row][col]);
			point->x *= rate;
			point->y *= rate;
			col++;
		}
		row++;
	}
}
