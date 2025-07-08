/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:43:31 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/08 13:58:29 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	top_projection(t_map *map, t_point *point, int i, int j)
{
	int	offset_x;
	int	offset_y;

	offset_x = (WIN_LENGTH / 2) + map->x_offset;
	offset_y = (WIN_HEIGHT / 2) + map->x_offset;
	point->x = ((j - map->width / 2) * map->zoom) * cos(map->rotate)
		- ((i - map->height / 2) * map->zoom) * sin(map->rotate);
	point->y = ((j - map->width / 2) * map->zoom) * sin(map->rotate)
		+ ((i - map->height / 2) * map->zoom) * cos(map->rotate);
	point->x += offset_x;
	point->y += offset_y;
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

	proj[0] = (map->width + map->height) / 5 * map->zoom * cos(0.866);
	proj[1] = (map->width + map->height) / 5 * map->zoom * sin(0.5);
	offset[0] = (WIN_LENGTH - proj[0]) / 2 + map->x_offset;
	offset[1] = (WIN_HEIGHT - proj[1]) / 2 + map->y_offset;
	x = ((j - map->width / 2) * map->zoom) * cos(map->rotate)
		- ((i - map->height / 2) * map->zoom) * sin(map->rotate);
	y = ((j - map->width / 2) * map->zoom) * sin(map->rotate)
		+ ((i - map->height / 2) * map->zoom) * cos(map->rotate);
	point->x = (x - y) * cos(0.866) + offset[0];
	point->y = (x + y) * sin(0.5) - map->tab[i][j].z * 2 + offset[1];
	point->z = map->tab[i][j].z;
	point->color = map->tab[i][j].color;
}

void	text_projection(t_data *d)
{
	mlx_string_put(d->mlx, d->win, 20, 30, 0xFFFFFF, "INPUTS");
	mlx_string_put(d->mlx, d->win, 20, 60, 0xFFFFFF, "ZOOM : MOUSE WHEEL");
	mlx_string_put(d->mlx, d->win, 20, 90, 0xFFFFFF, "MOVE : ARROWS");
	mlx_string_put(d->mlx, d->win, 20, 120, 0xFFFFFF, "PROJECTIONS :");
	mlx_string_put(d->mlx, d->win, 30, 140, 0xFFFFFF, "ISOMETRIC : I");
	mlx_string_put(d->mlx, d->win, 30, 160, 0xFFFFFF, "TOP : O");
	mlx_string_put(d->mlx, d->win, 30, 180, 0xFFFFFF, "SIDE : P");
	mlx_string_put(d->mlx, d->win, 20, 210, 0xFFFFFF, "RESET MOVEMENT : R");
	mlx_string_put(d->mlx, d->win, 20, 240, 0xFFFFFF, "INCREASE HEIGHT : -");
	mlx_string_put(d->mlx, d->win, 20, 260, 0xFFFFFF, "DECREASE HEIGHT : +");
	mlx_string_put(d->mlx, d->win, 20, 290, 0xFFFFFF, "ROTATE -> : N");
	mlx_string_put(d->mlx, d->win, 20, 310, 0xFFFFFF, "ROTATE <- : M");
}
