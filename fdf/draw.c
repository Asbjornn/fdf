/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:17:33 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/27 13:15:11 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	draw_line(int x1, int x2, int y1, int y2, t_data *data)
// {
// 	int	tmpx1 = x1;
// 	int	tmpy1 = y1;

// 	while (x1 != x2)
// 	{
// 		mlx_pixel_put((*data).mlx, (*data).win, x1, y1, 0xFFFFFF);
// 		if (x1 != x2)
// 			x1++;
// 		// if (y1 != y2)
// 		// 	y1++;
// 	}
// 	while (y1 != y2)
// 	{
// 		mlx_pixel_put((*data).mlx, (*data).win, x1, y1, 0xFFFFFF);
// 		if (y1 != y2)
// 			y1++;
// 	}
// 	while (x1 != tmpx1)
// 	{
// 		mlx_pixel_put((*data).mlx, (*data).win, x1, y1, 0xFFFFFF);
// 		if (x1 != tmpx1)
// 			x1--;
// 	}
// 	while (y1 != tmpy1)
// 	{
// 		mlx_pixel_put((*data).mlx, (*data).win, x1, y1, 0xFFFFFF);
// 		if (y1 != tmpy1)
// 			y1--;
// 	}
// }

// void	get_line(t_point **point_a, t_point **point_b, t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < data->map->height)
// 	{
// 		j = 0;
// 		while (i < data->map->width)
// 		{
// 			iso_projection(point_a, i, j, (*data).map->tab[i][j]);
// 		}
// 		i++;
// 	}
// }

static void	do_line(t_data *data, t_point *point, int i, int j)
{
	int	temp_x;

	if (j < data->map->width - 1)
	{
		temp_x = point->x;
		while (temp_x != point->x2)
		{
			mlx_pixel_put(data->mlx, data->win, temp_x, point->y, 0x00FF0000);
			temp_x++;
		}
	}
	if (i < data->map->height - 1)
	{
		while (point->y != point->y2)
		{
			mlx_pixel_put(data->mlx, data->win, point->x, point->y, 0x0000FFFF);
			point->y++;
		}
	}
}

void	draw_map_top(t_data *data)
{
	t_point	*point;
	int		i;
	int		j;

	i = 0;
	point = malloc(sizeof(t_point));
	if (!point)
		display_error("malloc point failed", 2);
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			point->x = j * 50 + data->map->x_offset;
			point->y = i * 50 + data->map->y_offset;
			point->x2 = (j + 1) * 50 + data->map->x_offset;
			point->y2 = (i + 1) * 50 + data->map->y_offset;
			do_line(data, point, i, j);
			j++;
		}
		i++;
	}
	free(point);
}

static void	iso_projection_test(t_data *data, t_point **point, int i, int j)
{
	int	x;
	int	y;
	int	x2;
	int	y2;

	x = j * 50;
	y = i * 50;
	(*point)->x = ((x - y) * cos(0.523599)) + data->map->x_offset;
	(*point)->y = (x + y) * sin(0.523599) - data->map->tab[i][j];
	(*point)->y += data->map->y_offset;
	x2 = (j + 1) * 50;
	y2 = (i + 1) * 50;
	(*point)->x2 = ((x2 - y2) * cos(0.523599)) + data->map->x_offset;
	(*point)->y2 = (x2 + y2) * sin(0.523599) - data->map->tab[i][j + 1];
	(*point)->y2 += data->map->y_offset;
}

void	do_bresenham(t_data *data, t_point *point)
{
	point->dx = point->x2 - point->x;
	point->dy = point->y2 - point->y;
	point->err = point->dx - point->dy;
	if (point->x < point->x2)
		point->sx = 1;
	else
		point->sx = -1;
	if (point->y < point->y2)
		point->sy = 1;
	else
		point->sy = -1;
	while (point->x != point->x2 || point->y != point->y2)
	{
		mlx_pixel_put(data->mlx, data->win, point->x, point->y, 0xFFFFFF);
		point->err = 2 * point->err;
		if (point->err > -point->dy)
		{
			point->err -= point->dy;
			point->x += point->sx;
		}
		if (point->err < point->dx)
		{
			point->err += point->dx;
			point->y += point->sy;
		}
	}
}

void	draw_map_iso(t_data *data)
{
	t_point	*point;
	int		i;
	int		j;

	i = 0;
	point = malloc(sizeof(t_point));
	if (!point)
		display_error("malloc point failed", 2);
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			iso_projection_test(data, &point, i, j);
			do_bresenham(data, point);
			j++;
		}
		i++;
	}
	free(point);
}


