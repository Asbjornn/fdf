/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:08:03 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/08 13:26:02 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_error(char *message, int fd)
{
	ft_putstr_fd(message, fd);
	ft_putchar_fd('\n', fd);
	exit(1);
}

static void	fill_point_tab(t_tab_point *tab, t_tab_point *src)
{
	tab->x = src->x;
	tab->y = src->y;
	tab->z = src->z;
	tab->color = src->color;
}

t_tab_point	**copy_tab(t_tab_point **src, t_map *map)
{
	t_tab_point	**tab;
	int			i;
	int			j;

	i = 0;
	tab = malloc(sizeof(t_tab_point *) * map->height);
	if (!tab)
		display_error("malloc1 failed in copy_tab", 2);
	while (i < (*map).height)
	{
		j = 0;
		tab[i] = malloc(sizeof(t_tab_point) * map->width);
		if (!tab[i])
		{
			free_point_tab(tab);
			display_error("malloc2 failed i copy_tab", 2);
		}
		while (j < (*map).width)
		{
			fill_point_tab(&tab[i][j], &src[i][j]);
			j++;
		}
		i++;
	}
	return (tab);
}

int	get_zoom(t_map map)
{
	if (map.width <= 20)
		return (50);
	else if (map.width <= 40)
		return (40);
	else if (map.width <= 60)
		return (20);
	else if (map.width <= 80)
		return (10);
	else
		return (5);
}
