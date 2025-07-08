/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:21:44 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/08 11:32:37 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	i = 0;
	while (i < (*map)->height)
	{
		free((*map)->origine_tab[i]);
		i++;
	}
	free((*map)->origine_tab);
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

void	free_point_tab(t_tab_point **tab)
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
