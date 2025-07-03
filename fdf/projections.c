/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:43:31 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/03 14:47:17 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	last_line(t_data *data, t_point point, t_point point2,
		void (*projection)(t_map *map, t_point *point, int i, int j))
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map->height - 1)
	{
		projection(data->map, &point, i, data->map->width - 1);
		projection(data->map, &point2, i + 1, data->map->width - 1);
		draw_line(data, point, point2);
		i++;
	}
	while (j < data->map->width - 1)
	{
		projection(data->map, &point, data->map->height - 1, j);
		projection(data->map, &point2, data->map->height - 1, j + 1);
		draw_line(data, point, point2);
		j++;
	}
}

void	top_projection(t_map *map, t_point *point, int i, int j)
{
	int	offset_x;
	int	offset_y;

	offset_x = (WIN_LENGTH / 2) - (map->height / 2) * map->zoom;
	offset_y = (WIN_HEIGHT / 2) - (map->width / 2) * map->zoom;
	point->x = j * map->zoom + (offset_x + map->x_offset);
	point->y = i * map->zoom + (offset_y + map->y_offset);
	point->z = map->tab[i][j];
}

void	side_projection(t_map *map, t_point *point, int i, int j)
{
	int	offset_x;
	int	offset_y;

	offset_x = (WIN_LENGTH - (map->width - 1)) / 2;
	offset_x -= (map->width * map->zoom) / 2;
	offset_y = WIN_HEIGHT / 1.2;
	point->x = j * map->zoom + (offset_x + map->x_offset);
	point->z = map->tab[i][j];
	point->y = -point->z * map->zoom + (offset_y + map->y_offset);
}

void	iso_projection(t_map *map, t_point *point, int i, int j)
{
	int	x;
	int	y;
	int	offset[2];
	int	proj[2];

	proj[0] = (map->width + map->height) / 5 * map->zoom * cos(ISO_ANGLE);
	proj[1] = (map->width + map->height) * map->zoom * sin(ISO_ANGLE);
	offset[0] = (WIN_LENGTH - proj[0]) / 2 + map->x_offset;
	offset[1] = (WIN_HEIGHT - proj[1]) / 2 + map->y_offset;
	x = j * map->zoom;
	y = i * map->zoom;
	point->x = (x - y) * cos(ISO_ANGLE) + offset[0];
	point->y = (x + y) * sin(ISO_ANGLE) - map->tab[i][j] * 2 + offset[1];
	point->z = map->tab[i][j];
}
