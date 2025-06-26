/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:24:30 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/26 16:09:33 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define ESCAPE		65307
# define WIN_LENGTH	1920
# define WIN_HEIGHT	1080

typedef struct s_map
{
	int		height;
	int		width;
	int		x_offset;
	int		y_offset;
	int		zoom;
	int		**tab;
}			t_map;

typedef struct s_point
{
	int		x;
	int		y;
	int		x2;
	int		y2;
	int		err;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
}			t_point;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	*map;
}			t_data;

void	draw_map_top(t_data *data);
void	draw_map_iso(t_data *data);

void	bressenham(t_data *data);

t_map	*parse(int argc, char *argv[]);

void	display_error(char *message, int fd);
void	free_tab(char **tab);
void	free_map(t_map **map);

void	ft_swap(int *a, int *b);

#endif