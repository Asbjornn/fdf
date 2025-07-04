/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:43:31 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/04 16:56:05 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	top_projection(t_map *map, t_point *point, int i, int j)
{
	int	offset_x;
	int	offset_y;

	offset_x = (WIN_LENGTH / 2) - (map->height / 2) * map->zoom;
	offset_y = (WIN_HEIGHT / 2) - (map->width / 2) * map->zoom;
	point->x = j * map->zoom + (offset_x + map->x_offset);
	point->y = i * map->zoom + (offset_y + map->y_offset);
	point->z = map->tab[i][j].z;
	point->color = map->tab[i][j].color;
}

void	side_projection(t_map *map, t_point *point, int i, int j)
{
	int	offset_x;
	int	offset_y;

	offset_x = (WIN_LENGTH - (map->width - 1)) / 2;
	offset_x -= (map->width * map->zoom) / 2;
	offset_y = WIN_HEIGHT / 1.2;
	point->x = j * map->zoom + (offset_x + map->x_offset);
	point->z = map->tab[i][j].z;
	point->y = -point->z * map->zoom + (offset_y + map->y_offset);
	point->color = map->tab[i][j].color;
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
	point->y = (x + y) * sin(ISO_ANGLE) - map->tab[i][j].z * 2 + offset[1];
	point->z = map->tab[i][j].z;
	point->color = map->tab[i][j].color;
}

void	text_projection(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 20, 30, 0xFFFFFF, "INPUTS");
	mlx_string_put(data->mlx, data->win, 20, 60, 0xFFFFFF, "ZOOM : MOUSE WHEEL");
	mlx_string_put(data->mlx, data->win, 20, 80, 0xFFFFFF, "MOVE : ARROWS");
	mlx_string_put(data->mlx, data->win, 20, 110, 0xFFFFFF, "PROJECTIONS :");
	mlx_string_put(data->mlx, data->win, 30, 130, 0xFFFFFF, "ISOMETRIC : I");
	mlx_string_put(data->mlx, data->win, 30, 150, 0xFFFFFF, "TOP : O");
	mlx_string_put(data->mlx, data->win, 30, 170, 0xFFFFFF, "SIDE : P");
	mlx_string_put(data->mlx, data->win, 20, 200, 0xFFFFFF, "RESET MOVEMENT : R");
	mlx_string_put(data->mlx, data->win, 20, 230, 0xFFFFFF, "INCREASE HEIGHT : -");
	mlx_string_put(data->mlx, data->win, 20, 250, 0xFFFFFF, "DECREASE HEIGHT : +");
}
