/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:58:00 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/01 14:52:46 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_height(char *file)
{
	char	*line;
	int		height;
	int		fd;

	height = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		display_error("open failed in get_height", 2);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	close (fd);
	return (height);
}

static int	get_width(char *file)
{
	char	**split;
	char	*line;
	int		width;
	int		fd;

	width = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		display_error("open failed in get_width", 2);
	line = get_next_line(fd);
	if (!line)
		display_error("empty file", 2);
	split = ft_split(line, ' ');
	while (split[width] && ft_strncmp(split[width], "\n", 2) != 0)
		width++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	free_tab(split);
	close (fd);
	return (width);
}

static void	fill_string(t_map **map, char *line, int i)
{
	char	**split;
	int		j;

	j = 0;
	split = ft_split(line, ' ');
	while (split[j] && ft_strncmp(split[j], "\n", 2) != 0)
	{
		(*map)->tab[i][j] = ft_atoi(split[j]);
		j++;
	}
	free_tab(split);
}

static void	fill_tab(t_map **map, char *file)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		display_error("open failed in fill_tab", 2);
	line = get_next_line(fd);
	while (line)
	{
		(*map)->tab[i] = malloc(sizeof(int) * (*map)->width);
		if (!(*map)->tab[i])
		{
			free_map(map);
			close(fd);
			display_error("malloc failed in fill_tab", 2);
		}
		fill_string(map, line, i);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
}

t_map	*parse(int argc, char *argv[])
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		display_error("malloc map failed", 2);
	map->height = get_height(argv[1]);
	map->width = get_width(argv[1]);
	map->zoom = get_zoom((*map));
	map->x_offset = (WIN_LENGTH - (map->width - 1)) / 1;
	map->x_offset -= ((map->width - 1) * map->zoom) / 1;
	map->y_offset = (WIN_HEIGHT - (map->height - 1)) / 2;
	map->y_offset -= ((map->height - 1) * map->zoom) / 2;
	map->rotate = 0;
	ft_printf("height map = %d\n", map->height);
	ft_printf("width map = %d\n", map->width);
	map->tab = malloc(sizeof(int *) * (map->height));
	if (!map->tab)
		display_error("malloc map tab failed", 2);
	fill_tab(&map, argv[1]);
	get_z_height(&map);
	map->origine_tab = copy_tab(map->tab, map);
	return (map);
}
