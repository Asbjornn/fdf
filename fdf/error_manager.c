/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:29:34 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/16 13:57:31 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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