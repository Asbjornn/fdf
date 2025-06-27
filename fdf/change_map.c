/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:21:59 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/27 16:15:13 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_map(t_data *data, int keycode)
{
	if (keycode == LEFT)
		data->map->x_offset -= 50;
	if (keycode == RIGHT)
		data->map->x_offset += 50;
	if (keycode == UP)
		data->map->y_offset -= 50;
	if (keycode == DOWN)
		data->map->y_offset += 50;
	if (keycode == LETTER_N)
		data->map->rotate++;
	if (keycode == LETTER_M)
		data->map->rotate--;
	mlx_clear_window(data->mlx, data->win);
	bressenham_iso(data);
}

int	get_mouse(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (button == SCROLL_UP)
	{
		ft_printf("scroll up\n");
		data->map->zoom += 10;
	}
	else if (button == SCROLL_DOWN)
	{
		ft_printf("scroll down\n");
		data->map->zoom -= 10;
	}
	else
		return (0);
	mlx_clear_window(data->mlx, data->win);
	bressenham_iso(data);
}

static void	change_in_tab_height(t_data *data, int value)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->height - 1)
	{
		j = 0;
		while (j < data->map->width - 1)
		{
			if (data->map->tab[i][j] + value == 0)
				data->map->tab[i][j] = 1;
			else if (data->map->tab[i][j] != 0)
				data->map->tab[i][j] += value;
			j++;
		}
		i++;
	}
}

void	change_height(t_data *data, int keycode)
{
	if (keycode == MINUS1 || keycode == MINUS2)
		change_in_tab_height(data, -5);
	if (keycode == PLUS1 || keycode == PLUS2)
		change_in_tab_height(data, 5);
	mlx_clear_window(data->mlx, data->win);
	bressenham_iso(data);
}

void	change_view(t_data *data, int keycode)
{
	if (keycode == ISO_PROJ)
	{
		mlx_clear_window(data->mlx, data->win);
		bressenham_iso(data);
	}
	if (keycode == TOP_PROJ)
	{
		mlx_clear_window(data->mlx, data->win);
		bressenham_top(data);
	}
}
