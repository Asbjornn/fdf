/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:24:30 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/27 15:09:32 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  INCLUDES  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  DEFINES  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

// # define ISO_ANGLE		0.523599
# define ISO_ANGLE		0.65
# define ZOOM			50
# define ESCAPE			65307
# define WIN_LENGTH		1920
# define WIN_HEIGHT		1080
# define SCROLL_UP		4
# define SCROLL_DOWN	5
# define LEFT			65361
# define UP				65362
# define RIGHT			65363
# define DOWN			65364
# define MINUS1			65453
# define MINUS2			45
# define PLUS1			65451
# define PLUS2			61
# define TOP_PROJ		116
# define ISO_PROJ		105
# define LETTER_N		110
# define LETTER_M		109

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~  STRUCTURES  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

typedef struct s_map
{
	int			height;
	int			width;
	int			x_offset;
	int			y_offset;
	int			zoom;
	double		rotate;
	int			**tab;
}			t_map;

typedef struct s_point
{
	int		x;
	int		y;
	int		x2;
	int		y2;
	int		err;
	int		err2;
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

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~  PROJECTIONS  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void	top_projection(t_data *data, t_point *point, int i, int j);
void	iso_projection(t_data *data, t_point *point, int i, int j);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  ALGO  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void	bressenham_iso(t_data *data);
void	bressenham_top(t_data *data);

t_map	*parse(int argc, char *argv[]);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  UTILS  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void	display_error(char *message, int fd);
void	free_tab(char **tab);
void	free_map(t_map **map);
void	ft_swap(int *a, int *b);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  BONUS  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void	move_map(t_data *data, int keycode);
void	change_height(t_data *data, int keycode);
int		get_mouse(int button, int x, int y, void *param);
void	change_view(t_data *data, int keycode);

#endif