/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:23:47 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/11 15:53:30 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	main(void)
{
	t_data	data;

	ft_printf("Hello world !\nAnd\nfdf hahaha\n");
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "fdf");
	mlx_key_hook(data.win, get_key, &data);
	mlx_loop(data.mlx);
	return (0);
}
