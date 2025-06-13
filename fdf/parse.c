/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:58:00 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/13 17:20:32 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse(int argc, char *argv[])
{
	t_coor	**co;
	char	*line;
	int		fd;
	int		i;

	i = 1;
	fd = open(argv[argc - 1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		get_next_line(fd);
		i++;
	}
	co = malloc(sizeof(t_coor) * i);
}
