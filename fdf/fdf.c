/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:23:47 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/13 17:03:16 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
	return (0);
}

int	get_key(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_printf("Hello world !\nAnd\nfdf hahaha\n");
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "fdf");
	parse(argc, argv);
	draw_line(400, 600, 400, 600, data);
	draw_line(700, 900, 400, 600, data);
	draw_line(400, 900, 700, 900, data);
	// test
	draw_line(400, 600, 800, 1000, data);
	draw_line(600, 800, 800, 1000, data);
	draw_line(500, 700, 200, 800, data);
	mlx_key_hook(data.win, get_key, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
