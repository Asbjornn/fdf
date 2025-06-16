/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:24:30 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/16 10:33:38 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
// # include "../minilibx-linux/mlx.h"
// # include "../minilibx-linux/mlx_int.h"

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

typedef struct s_map
{
	int		height;
	int		width;
	int		**tab;
}			t_map;

void	draw_line(int x1, int y1, int x2, int y2, t_data data);

t_map	*parse(int argc, char *argv[]);

#endif