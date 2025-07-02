/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:43:31 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/02 16:19:58 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	last_line(t_data *data, t_point point, t_point point2,
		void (*projection)(t_data *data, t_point *point, int i, int j))
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map->height - 1)
	{
		projection(data, &point, i, data->map->width - 1);
		projection(data, &point2, i + 1, data->map->width - 1);
		draw_line(data, point, point2);
		i++;
	}
	while (j < data->map->width - 1)
	{
		projection(data, &point, data->map->height - 1, j);
		projection(data, &point2, data->map->height - 1, j + 1);
		draw_line(data, point, point2);
		j++;
	}
}

void	top_projection(t_data *data, t_point *point, int i, int j)
{
	data->map->x_offset = (WIN_LENGTH / 2) - (data->map->height / 2) * data->map->zoom;
	data->map->y_offset = (WIN_HEIGHT / 2) - (data->map->width / 2) * data->map->zoom;
	point->x = j * data->map->zoom + data->map->x_offset;
	point->y = i * data->map->zoom + data->map->y_offset;
	point->z = data->map->tab[i][j];
}

void	side_projection(t_data *data, t_point *point, int i, int j)
{
	data->map->x_offset = (WIN_LENGTH - (data->map->width - 1)) / 2;
	data->map->y_offset = (WIN_HEIGHT - (data->map->height - 1)) / 2;
	point->x = j * data->map->zoom + data->map->x_offset;
	point->z = data->map->tab[i][j];
	point->y = -point->z * data->map->zoom + data->map->y_offset;
}

void	iso_projection(t_data *data, t_point *point, int i, int j)
{
	int	x;
	int	y;

	data->map->x_offset = (WIN_LENGTH - (data->map->width - 1)) / 1;
	data->map->x_offset -= ((data->map->width - 1) * data->map->zoom) / 1;
	data->map->y_offset = (WIN_HEIGHT - (data->map->height - 1)) / 2;
	data->map->y_offset -= ((data->map->height - 1) * data->map->zoom) / 2;
	x = j * data->map->zoom;
	y = i * data->map->zoom;
	point->x = ((x - y) * cos(ISO_ANGLE)) + data->map->x_offset;
	point->y = ((x + y) * sin(ISO_ANGLE)) - data->map->tab[i][j] * 2;
	point->y += data->map->y_offset * 0.5;
	point->z = data->map->tab[i][j];
}
