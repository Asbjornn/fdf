/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:23:47 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/27 16:22:56 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	free_map(&data->map);
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
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free(data);
		exit (0);
	}
	if ((keycode >= LEFT && keycode <= DOWN)
		|| keycode == LETTER_M || keycode == LETTER_N)
		move_map(data, keycode);
	if (keycode == MINUS1 || keycode == MINUS2
		|| keycode == PLUS1 || keycode == PLUS2)
		change_height(data, keycode);
	if (keycode == TOP_PROJ || keycode == ISO_PROJ)
		change_view(data, keycode);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
		display_error("format: ./fdf 'file.fdf'\n", 2);
	data = malloc(sizeof(t_data));
	if (!data)
		display_error("malloc failed in main", 2);
	data->map = parse(argc, argv);
	(*data).mlx = mlx_init();
	(*data).win = mlx_new_window((*data).mlx, WIN_LENGTH, WIN_HEIGHT, "fdf");
	// draw_map_top(data);
	// draw_map_iso(data);
	bressenham_iso(data);
	mlx_key_hook((*data).win, get_key, data);
	mlx_mouse_hook((*data).win, get_mouse, data);
	mlx_hook((*data).win, 17, 0, close_window, data);
	mlx_loop((*data).mlx);
	return (0);
}
