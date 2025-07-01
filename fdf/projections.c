/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:43:31 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/01 12:47:29 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	top_projection(t_data *data, t_point *point, int i, int j)
{
	point->x = j * data->map->zoom + data->map->x_offset;
	point->y = i * data->map->zoom + data->map->y_offset;
	point->z = data->map->tab[i][j];
}

void	iso_projection(t_data *data, t_point *point, int i, int j)
{
	int	x;
	int	y;

	x = j * data->map->zoom;
	y = i * data->map->zoom;
	point->x = ((x - y) * cos(ISO_ANGLE)) + data->map->x_offset;
	point->y = ((x + y) * sin(ISO_ANGLE)) - data->map->tab[i][j] * 2;
	point->y += data->map->y_offset;
	point->z = data->map->tab[i][j];
}
