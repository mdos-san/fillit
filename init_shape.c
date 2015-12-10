/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         :+:     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+        +#+       */
/*                                                +#+#+#+#+#+    +#+          */
/*   Created: 2015/12/07 23:43:58 by mdos-san          #+#     #+#            */
/*   Updated: 2015/12/09 14:38:59 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "dbl_tab.h"

int	init_shape(t_tetri *tet, int fd)
{
	int		x;
	int 	y;
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
