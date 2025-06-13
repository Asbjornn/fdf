/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:24:30 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/13 17:02:56 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# define ESCAPE 65307

typedef struct s_data
{
	void	*mlx;
	void	*win;
}			t_data;

typedef struct s_coor
{
	int		x;
	int		y;
	int		z;
}			t_coor;

void	draw_line(int x1, int y1, int x2, int y2, t_data data);

void	parse(int argc, char *argv[]);

#endif