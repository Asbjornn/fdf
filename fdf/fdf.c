/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:23:47 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/08 13:25:56 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	free_map(&data->map);
	free((*data).map);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit (0);
	return (0);
}

int	get_key(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == ESCAPE)
	{
		free_map(&data->map);
		free((*data).map);
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free(data);
		exit (0);
	}
	if ((keycode >= LEFT && keycode <= DOWN)
		|| keycode == LETTER_M || keycode == LETTER_N || keycode == LETTER_R)
		move_map(data, keycode);
	if (keycode == MINUS1 || keycode == MINUS2
		|| keycode == PLUS1 || keycode == PLUS2)
		change_height(data, keycode);
	if (keycode == TOP_PROJ || keycode == ISO_PROJ || keycode == SIDE_PROJ)
		change_view(data, keycode);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
		display_error("format: ./fdf 'file.fdf'", 2);
	data = malloc(sizeof(t_data));
	if (!data)
		display_error("malloc failed in main", 2);
	data->map = parse(argv);
	data->mlx = mlx_init();
	data->win = mlx_new_window((*data).mlx, WIN_LENGTH, WIN_HEIGHT, "fdf");
	data->img = mlx_new_image((*data).mlx, WIN_LENGTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr((*data).img, &(*data).bits_per_pixel,
			&(*data).line_length, &(*data).endian);
	bressenham(data, iso_projection);
	text_projection(data);
	mlx_key_hook((*data).win, get_key, data);
	mlx_mouse_hook((*data).win, get_mouse, data);
	mlx_hook((*data).win, 17, 0, close_window, data);
	mlx_loop((*data).mlx);
	return (0);
}
