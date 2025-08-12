/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:06:33 by squinn            #+#    #+#             */
/*   Updated: 2025/08/12 11:52:17 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_pixel(int x, int y, t_image *img, uint32_t color)
{
	int		bytes_per_pixel;
	int		offset;
	char	*pixel_addr;

	bytes_per_pixel = img->bits_per_pixel / 8;
	offset = img->row_size * y + x * bytes_per_pixel;
	pixel_addr = img->address + offset;
	*(uint32_t *)pixel_addr = color;
}

void	draw_gentle_line(t_point a, t_point b, t_image *img)
{
	int			discriminant;
	int			x;
	int			y;
	int			i;
	uint32_t	color;

	discriminant = 2 * ft_abs(a.dy) - ft_abs(a.dx);
	set_pixel(a.transformed_x, a.transformed_y, img, a.color);
	x = a.transformed_x;
	y = a.transformed_y;
	i = -1;
	while (++i < ft_abs(a.dx))
	{
		x += get_direction(a.dx);
		color = get_color_gradient(a, b, x, TRUE);
		if (discriminant < 0)
		{
			set_pixel(x, y, img, color);
			discriminant += 2 * ft_abs(a.dy);
			continue ;
		}
		y += get_direction(a.dy);
		set_pixel(x, y, img, color);
		discriminant += 2 * ft_abs(a.dy) - 2 * ft_abs(a.dx);
	}
}

void	draw_steep_line(t_point a, t_point b, t_image *img)
{
	int			discriminant;
	int			x;
	int			y;
	int			i;
	uint32_t	color;

	discriminant = ft_abs(a.dy) - 2 * ft_abs(a.dx);
	set_pixel(a.transformed_x, a.transformed_y, img, a.color);
	x = a.transformed_x;
	y = a.transformed_y;
	i = -1;
	while (++i < ft_abs(a.dy))
	{
		y += get_direction(a.dy);
		color = get_color_gradient(a, b, y, FALSE);
		if (discriminant > 0)
		{
			set_pixel(x, y, img, color);
			discriminant += -2 * ft_abs(a.dx);
			continue ;
		}
		x += get_direction(a.dx);
		set_pixel(x, y, img, color);
		discriminant += 2 * ft_abs(a.dy) - 2 * ft_abs(a.dx);
	}
}

void	draw_line(t_point a, t_point b, t_image *img)
{
	a.dx = b.transformed_x - a.transformed_x;
	a.dy = b.transformed_y - a.transformed_y;
	if (ft_abs(a.dx) > ft_abs(a.dy))
		return (draw_gentle_line(a, b, img));
	return (draw_steep_line(a, b, img));
}

int	draw_map(t_data *data)
{
	t_point	**grid;
	int		row;
	int		col;

	if (data->window == NULL)
		return (FAILED);
	grid = data->map.grid;
	row = 0;
	while (row < data->map.num_rows)
	{
		col = 0;
		while (col < data->map.num_cols)
		{
			if (col < data->map.num_cols - 1)
				draw_line(grid[row][col], grid[row][col + 1], &data->img);
			if (row < data->map.num_rows - 1)
				draw_line(grid[row][col], grid[row + 1][col], &data->img);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img.mlx_img, 0, 0);
	return (SUCESS);
}
