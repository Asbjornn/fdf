/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:08:03 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/27 13:39:49 by gcauchy          ###   ########.fr       */
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

void	free_map(t_map **map)
{
	int	i;

	i = 0;
	while (i < (*map)->height)
	{
		free((*map)->tab[i]);
		i++;
	}
	free((*map)->tab);
}
