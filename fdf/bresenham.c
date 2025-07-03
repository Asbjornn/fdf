/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:04:00 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/03 14:23:41 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_coor(t_point *point, t_point point2)
{
	point->dx = abs(point2.x - point->x);
	point->dy = abs(point2.y - point->y);
	point->err = point->dx - point->dy;
	if (point->x < point2.x)
		point->sx = 1;
	else
		point->sx = -1;
	if (point->y < point2.y)
		point->sy = 1;
	else
		point->sy = -1;
}

void	draw_line(t_data *data, t_point point, t_point point2)
{
	int	i;

	i = 0;
	get_coor(&point, point2);
	while (1)
	{
		my_mlx_pixel_put(data, point.x, point.y,
			set_colors(point, point2, i, data));
		if (point.x == point2.x && point.y == point2.y)
			break ;
		point.err2 = point.err * 2;
		if (point.err2 > -point.dy)
		{
			point.err -= point.dy;
			point.x += point.sx;
		}
		if (point.err2 < point.dx)
		{
			point.err += point.dx;
			point.y += point.sy;
		}
		i++;
	}
}

void	bressenham(t_data *data,
	void (*projection)(t_map *map, t_point *point, int i, int j))
{
	t_point	point;
	t_point	point2;
	int		color;
	int		i;
	int		j;

	i = 0;
	get_z_height(&(*data).map);
	while (i < data->map->height - 1)
	{
		j = 0;
		while (j < data->map->width - 1)
		{
			projection(data->map, &point, i, j);
			projection(data->map, &point2, i + 1, j);
			draw_line(data, point, point2);
			projection(data->map, &point, i, j);
			projection(data->map, &point2, i, j + 1);
			draw_line(data, point, point2);
			j++;
		}
		i++;
	}
	last_line(data, point, point2, projection);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
