/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:04:00 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/26 16:24:11 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso_projection(t_data *data, t_point *point, int i, int j)
{
	int	x;
	int	y;

	x = j * 50;
	y = i * 50;
	point->x = ((x - y) * cos(0.523599)) + data->map->x_offset;
	point->y = (x + y) * sin(0.523599) - data->map->tab[i][j];
	point->y += data->map->y_offset;
}

static void	get_coor(t_point *point, t_point point2)
{
	point->dx = point2.x - point->x;
	point->dy = point2.y - point->y;
	point->err = point->dx - point->dy;
	if (point->dx < 0)
		point->sx = -1;
	else
		point->sx = 1;
	if (point->sy < 0)
		point->sy = -1;
	else
		point->sy = 1;
}

static void	draw_line_v(t_data *data, t_point point, t_point point2)
{
	int	x;

	ft_printf("vertical\n");
	if (point.y > point2.y)
	{
		ft_swap(&point.x, &point2.x);
		ft_swap(&point.y, &point2.y);
	}
	point.dx = point2.x - point.x;
	point.dy = point2.y - point.y;
	point.err = point.dx * 2 - point.dy;
	x = point.x;
	while (point.y != point2.y)
	{
		mlx_pixel_put(data->mlx, data->win, point.x, point.y, 0xFFFFFF);
		if (point.err >= 0)
		{
			x + point.sx;
			point.err -= (point.dy * 2);
		}
		point.err += (point.dy * 2);
		point.y++;
	}
}

static void	draw_line_h(t_data *data, t_point point, t_point point2)
{
	int	y;

	ft_printf("horizontal\n");
	if (point.x > point2.x)
	{
		ft_swap(&point.x, &point2.x);
		ft_swap(&point.y, &point2.y);
	}
	point.dx = point2.x - point.x;
	point.dy = point2.y - point.y;
	point.err = point.dx * 2 - point.dy;
	y = point.y;
	while (point.x != point2.x)
	{
		mlx_pixel_put(data->mlx, data->win, point.x, point.y, 0xFFFFFF);
		if (point.err >= 0)
		{
			y + point.sy;
			point.err -= (point.dx * 2);
		}
		point.err += (point.dx * 2);
		point.x++;
	}
}

void	bressenham(t_data *data)
{
	t_point	point;
	t_point	point2;
	int		i;
	int		j;

	i = 0;
	while (i < data->map->height - 1)
	{
		j = 0;
		while (j < data->map->width - 1)
		{
			iso_projection(data, &point, i, j);
			iso_projection(data, &point2, i + 1, j);
			get_coor(&point, point2);
			draw_line_h(data, point, point2);
			iso_projection(data, &point, i, j);
			iso_projection(data, &point2, i, j + 1);
			get_coor(&point, point2);
			draw_line_v(data, point, point2);
			j++;
		}
		i++;
	}
}
