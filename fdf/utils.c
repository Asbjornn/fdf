/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:08:03 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/04 16:26:33 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_swap(int	*a, int *b)
{
	int	temp;

	temp = (*a);
	(*a) = (*b);
	(*b) = (*a);
}

void	display_error(char *message, int fd)
{
	ft_putstr_fd(message, fd);
	ft_putchar_fd('\n', fd);
	exit(1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_tab_point	**copy_tab(t_tab_point **src, t_map *map)
{
	t_tab_point	**tab;
	int			i;
	int			j;

	i = 0;
	tab = malloc(sizeof(t_tab_point *) * map->height);
	while (i < (*map).height)
	{
		j = 0;
		tab[i] = malloc(sizeof(t_tab_point) * map->width);
		while (j < (*map).width)
		{
			tab[i][j].x = src[i][j].x;
			tab[i][j].y = src[i][j].y;
			tab[i][j].z = src[i][j].z;
			tab[i][j].color = src[i][j].color;
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

