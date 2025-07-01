/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:04:00 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/01 13:23:10 by gcauchy          ###   ########.fr       */
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

static void	draw_line(t_data *data, t_point point, t_point point2)
{
	int	i;

	i = 0;
	get_coor(&point, point2);
	while (1)
	{
		mlx_pixel_put(data->mlx, data->win, point.x, point.y,
			test_colors(point, point2, i, data));
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

static void	last_line(t_data *data, t_point point, t_point point2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map->height - 1)
	{
		iso_projection(data, &point, i, data->map->width - 1);
		iso_projection(data, &point2, i + 1, data->map->width - 1);
		draw_line(data, point, point2);
		i++;
	}
	while (j < data->map->width - 1)
	{
		iso_projection(data, &point, data->map->height - 1, j);
		iso_projection(data, &point2, data->map->height - 1, j + 1);
		draw_line(data, point, point2);
		j++;
	}
}

void	bressenham_iso(t_data *data)
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
			iso_projection(data, &point, i, j);
			iso_projection(data, &point2, i + 1, j);
			draw_line(data, point, point2);
			iso_projection(data, &point, i, j);
			iso_projection(data, &point2, i, j + 1);
			draw_line(data, point, point2);
			j++;
		}
		i++;
	}
	last_line(data, point, point2);
}

void	bressenham_top(t_data *data)
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
			top_projection(data, &point, i, j);
			top_projection(data, &point2, i + 1, j);
			draw_line(data, point, point2);
			top_projection(data, &point, i, j);
			top_projection(data, &point2, i, j + 1);
			draw_line(data, point, point2);
			j++;
		}
		i++;
	}
	last_line(data, point, point2);
}

// =========================== OLD FUNCTIONS ============================
// 
// static void	draw_line_v(t_data *data, t_point point, t_point point2)
// {
// 	int	x;

// 	if (point.y > point2.y)
// 	{
// 		ft_swap(&point.x, &point2.x);
// 		ft_swap(&point.y, &point2.y);
// 	}
// 	x = point.x;
// 	while (point.y != point2.y)
// 	{
// 		mlx_pixel_put(data->mlx, data->win, x, point.y, 0xFFFFFF);
// 		if (point.err >= 0)
// 		{
// 			x += point.sx;
// 			point.err -= (point.dy * 2);
// 		}
// 		point.err += (point.dy * 2);
// 		point.y++;
// 	}
// }

// static void	draw_line_h(t_data *data, t_point point, t_point point2)
// {
// 	int	y;

// 	if (point.x > point2.x)
// 	{
// 		ft_swap(&point.x, &point2.x);
// 		ft_swap(&point.y, &point2.y);
// 	}
// 	y = point.y;
// 	while (point.x != point2.x)
// 	{
// 		mlx_pixel_put(data->mlx, data->win, point.x, y, 0xFFFFFF);
// 		if (point.err >= 0)
// 		{
// 			y += point.sy;
// 			point.err -= (point.dx * 2);
// 		}
// 		point.err += (point.dx * 2);
// 		point.x++;
// 	}
// }