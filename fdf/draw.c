/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:17:33 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/13 16:59:21 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(int x1, int x2, int y1, int y2, t_data data)
{
	int	tmpx1 = x1;
	int	tmpy1 = y1;

	while (x1 != x2)
	{
		mlx_pixel_put(data.mlx, data.win, x1, y1, 0xFFFFFF);
		if (x1 != x2)
			x1++;
		// if (y1 != y2)
		// 	y1++;
	}
	while (y1 != y2)
	{
		mlx_pixel_put(data.mlx, data.win, x1, y1, 0xFFFFFF);
		if (y1 != y2)
			y1++;
	}
	while (x1 != tmpx1)
	{
		mlx_pixel_put(data.mlx, data.win, x1, y1, 0xFFFFFF);
		if (x1 != tmpx1)
			x1--;
	}
	while (y1 != tmpy1)
	{
		mlx_pixel_put(data.mlx, data.win, x1, y1, 0xFFFFFF);
		if (y1 != tmpy1)
			y1--;
	}
}