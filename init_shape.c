/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:27:38 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/10 18:32:01 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

int	init_shape(t_tetri *tet, int fd)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	y = 0;
	c = 0;
	while (y < 4)
	{
		while (x < 5)
		{
			if (!read(fd, &c, 1))
				return (0);
			tet->shape[y][x] = c;
			x++;
		}
		x = 0;
		y++;
	}
	if (read(fd, &c, 1) > 0)
	{
		tetri_add(tet);
		init_shape(tet->next, fd);
	}
	return (1);
}
