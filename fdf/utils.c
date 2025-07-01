/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:08:03 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/01 13:17:13 by gcauchy          ###   ########.fr       */
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

int	**copy_tab(int **src, t_map *map)
{
	int	**tab;
	int	i;
	int	j;

	i = 0;
	tab = malloc(sizeof(int *) * map->height);
	while (i < (*map).height)
	{
		j = 0;
		tab[i] = malloc(sizeof(int) * map->width);
		while (j < (*map).width)
		{
			tab[i][j] = src[i][j];
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
