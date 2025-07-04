/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:45:55 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/04 16:27:48 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_z_height(t_map **map)
{
	int	i;
	int	j;

	i = 0;
	(*map)->min_z = 0;
	(*map)->max_z = 0;
	while (i < (*map)->height)
	{
		j = 0;
		while (j < (*map)->width)
		{
			if ((*map)->tab[i][j].z < (*map)->min_z)
				(*map)->min_z = (*map)->tab[i][j].z;
			if ((*map)->tab[i][j].z > (*map)->max_z)
				(*map)->max_z = (*map)->tab[i][j].z;
			j++;
		}
		i++;
	}
}

static int	color(int color1, int color2, float t)
{
	t_color	colors;
	int		r;
	int		g;
	int		b;

	colors.r_start = (color1 >> 16) & 0xFF;
	colors.g_start = (color1 >> 8) & 0xFF;
	colors.b_start = color1 & 0xFF;
	colors.r_end = (color2 >> 16) & 0xFF;
	colors.g_end = (color2 >> 8) & 0xFF;
	colors.b_end = color2 & 0xFF;
	r = colors.r_start + ((colors.r_end - colors.r_start) * t);
	g = colors.g_start + ((colors.g_end - colors.g_start) * t);
	b = colors.b_start + ((colors.b_end - colors.b_start) * t);
	return ((r << 16) | (g << 8) | b);
}

static int	color_for_z(int z, t_data *data)
{
	float	t;
	int		min;
	int		max;

	if (z == 0)
		return (ZERO_COLOR);
	min = (*data).map->min_z;
	max = (*data).map->max_z;
	if (z > 0)
	{
		t = (float)z / (float)max;
		return (color(ZERO_COLOR, POSITIV_COLOR, t));
	}
	else
	{
		t = (float)z / (float)min;
		return (color(ZERO_COLOR, NEGATIV_COLOR, t));
	}
}

int	set_colors(t_point point, t_point point2, int i, t_data *data)
{
	int	length;
	int	color1;
	int	color2;

	if (point.dx > point.dy)
		length = point.dx;
	else
		length = point.dy;
	if (point.color != 0)
		color1 = point.color;
	else
		color1 = color_for_z(point.z, data);
	if (point2.color != 0)
		color2 = point2.color;
	else
		color2 = color_for_z(point2.z, data);
	if (color1 == color2)
		return (color1);
	return (color(color1, color2, ((float)i / (float)length)));
}

int	ft_atoc(char *line)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (line[i] != ',' && line[i])
		i++;
	if (line[i] == '\0')
		return (0);
	while (line[i] != 'x')
		i++;
	while (line[++i])
	{
		if (line[i] == '\n')
			break ;
		result *= 16;
		if (line[i] >= 'A' && line[i] <= 'F')
			result += (line[i] - 'A') + 10;
		else if (line[i] >= 'a' && line[i] <= 'f')
			result += (line[i] - 'a') + 10;
		else
			result += line[i] - '0';
	}
	return (result);
}
