/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:24:30 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/04 16:35:24 by gcauchy          ###   ########.fr       */
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

# define WIN_LENGTH		1920
# define WIN_HEIGHT		1080

# define SCROLL_UP		4
# define SCROLL_DOWN	5

# define ESCAPE			65307
# define LEFT			65361
# define UP				65362
# define RIGHT			65363
# define DOWN			65364
# define MINUS1			65453
# define MINUS2			45
# define PLUS1			65451
# define PLUS2			61
# define ISO_PROJ		105
# define TOP_PROJ		111
# define SIDE_PROJ		112
# define LETTER_N		110
# define LETTER_M		109
# define LETTER_R		114

# define ZERO_COLOR		0x581845
# define POSITIV_COLOR	0xFFC30F
# define NEGATIV_COLOR	0x3c748c		

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~  STRUCTURES  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

typedef struct s_point
{
	int		x;
	int		y;
	int		x2;
	int		y2;
	int		z;
	int		err;
	int		err2;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		color;
}			t_point;

typedef struct s_color
{
	int	r_start;
	int	g_start;
	int	b_start;
	int	r_end;
	int	g_end;
	int	b_end;
}			t_color;

typedef struct s_tab_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}			t_tab_point;

typedef struct s_map
{
	int			height;
	int			width;
	int			x_offset;
	int			y_offset;
	int			min_z;
	int			max_z;
	int			zoom;
	double		rotate;
	int			is_iso;
	int			is_top;
	int			is_side;
	t_tab_point	**tab;
	t_tab_point	**origine_tab;
}			t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	*map;
	char	*addr;
	void	*img;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
}			t_data;

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~  PROJECTIONS  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void		top_projection(t_map *map, t_point *point, int i, int j);
void		iso_projection(t_map *map, t_point *point, int i, int j);
void		side_projection(t_map *map, t_point *point, int i, int j);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  ALGO  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void		bressenham(t_data *data,
				void (*projection)(t_map *map, t_point *point, int i, int j));

t_map		*parse(int argc, char *argv[]);
void		draw_line(t_data *data, t_point point, t_point point2);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		clear_image(t_data *data);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  UTILS  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void		display_error(char *message, int fd);
void		free_tab(char **tab);
void		free_map(t_map **map);
void		ft_swap(int *a, int *b);
int			get_zoom(t_map map);
int			set_colors(t_point point, t_point point2, int i, t_data *data);
void		get_z_height(t_map **map);
t_tab_point	**copy_tab(t_tab_point **src, t_map *map);
int			ft_atoc(char *line);
void		text_projection(t_data *data);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  BONUS  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void		move_map(t_data *data, int keycode);
void		change_height(t_data *data, int keycode);
int			get_mouse(int button, int x, int y, void *param);
void		change_view(t_data *data, int keycode);

#endif