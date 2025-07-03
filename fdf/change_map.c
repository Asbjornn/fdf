/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:21:59 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/03 13:05:25 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_map(t_data *data, int keycode)
{
	if (keycode == LEFT)
		data->map->x_offset -= 50;
	else if (keycode == RIGHT)
		data->map->x_offset += 50;
	else if (keycode == UP)
		data->map->y_offset -= 50;
	else if (keycode == DOWN)
		data->map->y_offset += 50;
	else if (keycode == LETTER_N)
		data->map->rotate++;
	else if (keycode == LETTER_M)
		data->map->rotate--;
	else if (keycode == LETTER_R)
	{
		data->map->x_offset = 0;
		data->map->y_offset = 0;
	}
	clear_image(data);
	if (data->map->is_iso)
		bressenham(data, iso_projection);
	if (data->map->is_top)
		bressenham(data, top_projection);
	if (data->map->is_side)
		bressenham(data, side_projection);
}

int	get_mouse(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (button == SCROLL_UP)
		data->map->zoom += 1;
	else if (button == SCROLL_DOWN)
		data->map->zoom -= 1;
	else
		return (0);
	clear_image(data);
	if (data->map->is_iso)
		bressenham(data, iso_projection);
	if (data->map->is_top)
		bressenham(data, top_projection);
	if (data->map->is_side)
		bressenham(data, side_projection);
}

static void	change_in_tab_height(t_data *data, int value)
{
	int	i;
	int	j;
	int	new_z;

	i = 0;
	new_z = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			new_z = data->map->tab[i][j] + value
				* (data->map->origine_tab[i][j] / 10);
			data->map->tab[i][j] = new_z;
			j++;
		}
		i++;
	}
	get_z_height(&data->map);
}

void	change_height(t_data *data, int keycode)
{
	if (keycode == MINUS1 || keycode == MINUS2)
		change_in_tab_height(data, -5);
	if (keycode == PLUS1 || keycode == PLUS2)
		change_in_tab_height(data, 5);
	clear_image(data);
	if (data->map->is_iso)
		bressenham(data, iso_projection);
	if (data->map->is_top)
		bressenham(data, top_projection);
	if (data->map->is_side)
		bressenham(data, side_projection);
}

void	change_view(t_data *data, int keycode)
{
	if (keycode == ISO_PROJ)
	{
		clear_image(data);
		data->map->is_iso = 1;
		data->map->is_top = 0;
		data->map->is_side = 0;
		bressenham(data, iso_projection);
	}
	if (keycode == TOP_PROJ)
	{
		clear_image(data);
		data->map->is_iso = 0;
		data->map->is_top = 1;
		data->map->is_side = 0;
		bressenham(data, top_projection);
	}
	if (keycode == SIDE_PROJ)
	{
		clear_image(data);
		data->map->is_iso = 0;
		data->map->is_top = 0;
		data->map->is_side = 1;
		bressenham(data, side_projection);
	}
}
