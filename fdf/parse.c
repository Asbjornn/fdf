/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:58:00 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/16 10:55:21 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_height(int fd, char *argv[])
{
	char	*line;
	int		height;

	height = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("error open");
		exit (1);
	}
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

static int	get_width(int fd, char *argv[])
{
	char	*line;
	int		width;
	int		i;

	width = 0;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("error open");
		exit (1);
	}
	line = get_next_line(fd);
	while (line[i])
	{
		if(ft_isdigit(line[i]) == 1 && (line[i + 1] == ' ' || line[i + 1] == '\n'))
			width++;
		i++;
	}
	while (line)
		line = get_next_line(fd);
	free(line);
	close (fd);
	return (width);
}

static void	fill_string(t_map **map, char *line, int i)
{
	int		j;
	int		h;

	j = 0;
	while (line[j])
	{
		h = 0;
		if (ft_isdigit(line[i]) == 1 && (line[i + 1] == ' ' || line[i + 1] == '\n'))
		{
			(*map)->tab[i][h] = (line[j] - 48);
			h++;
			i++;
		}
		j++;
	}
}

static void	fill_tab(t_map **map, int fd, char *argv[])
{
	char	*line;
	int		i;
	
	i = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		(*map)->tab[i] = malloc(sizeof(int) * (*map)->width);
		fill_string(&map, line, i);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
}

t_map	*parse(int argc, char *argv[])
{
	t_map	*map;
	int		fd;

	map = malloc(sizeof (t_map));
	if (!map)
	{
		ft_printf("error malloc");
		exit (1);
	}	
	map->height = get_height(fd, argv);
	map->width = get_width(fd, argv);
	map->tab = malloc(sizeof(int *) * map->height + 1);
	fill_tab(&map, fd, argv);
	for (size_t i = 0; i < map->height; i++)
	{
		for (size_t j = 0; j < map->width; j++)
		{
			ft_printf("tab n.%d, int.%d\n", map->tab[i], map->tab[i][j]);
		}
	}
	
	close(fd);
	return (map);
}
