/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:23:47 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/24 16:17:55 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	free_map(&data->map);
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
		free_map(&data->map);
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
	}
	return (0);
}

// void	printf_tab_stuct(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < (*data).map->height)
// 	{
// 		j = 0;
// 		while (j < (*data).map->width)
// 		{
// 			ft_printf("%d ", (*data).map->tab[i][j]);
// 			j++;
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}
// }

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
	draw_map_top(data);
	// draw_map_iso(data);
	mlx_key_hook((*data).win, get_key, data);
	mlx_hook((*data).win, 17, 0, close_window, data);
	mlx_loop((*data).mlx);
	return (0);
}

// draw_line(400, 600, 400, 600, data);
// draw_line(700, 900, 400, 600, data);
// draw_line(400, 900, 700, 900, data);
// draw_line(400, 600, 800, 1000, data);
// draw_line(600, 800, 800, 1000, data);
// draw_line(500, 700, 200, 800, data);