/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:43:00 by squinn            #+#    #+#             */
/*   Updated: 2025/08/12 11:43:02 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
Assumption:
- get_next_line works without error
- Map format is correct
*/
void	set_num_rows_and_columns(t_map *map, const char *filename)
{
	int		fd;
	char	*line;
	int		num_rows;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	map->num_cols = count_num_cols(line);
	free(line);
	num_rows = 1;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (count_num_cols(line) != map->num_cols)
		{
			free(line);
			close(fd);
			return (handle_error(INVALID_MAP));
		}
		free(line);
		num_rows += 1;
	}
	map->num_rows = num_rows;
	close(fd);
}

void	allocate_grid(t_map *map)
{
	t_point	**grid;
	int		row;

	grid = malloc(map->num_rows * sizeof(t_point *));
	if (grid == NULL)
		handle_error(MALLOC);
	row = 0;
	while (row < map->num_rows)
	{
		grid[row] = malloc(map->num_cols * sizeof(t_point));
		if (grid[row] == NULL)
		{
			free_grid(map);
			handle_error(MALLOC);
		}
		row++;
	}
	map->grid = grid;
}

/*
Assumption:
- get_next_line() works without error
- ft_split() works without error
*/
void	fill_one_row(t_map *map, int row, int fd)
{
	char		*line;
	char		**words;
	int			col;
	int			z;
	uint32_t	color;

	line = get_next_line(fd);
	words = ft_split(line, ' ');
	free(line);
	col = 0;
	while (col < map->num_cols)
	{
		z = ft_atoi(words[col]);
		color = parse_color(words[col]);
		map->grid[row][col] = new_point(col, row, z, color);
		col++;
	}
	free_words(words);
}

void	fill_grid(t_map *map, const char *filename)
{
	int	fd;
	int	row;

	fd = open(filename, O_RDONLY);
	row = 0;
	while (row < map->num_rows)
	{
		fill_one_row(map, row, fd);
		row++;
	}
	close(fd);
}

void	init_map(t_map *map, const char *filename)
{
	set_num_rows_and_columns(map, filename);
	allocate_grid(map);
	fill_grid(map, filename);
}
