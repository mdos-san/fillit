/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_valide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:15:11 by ajubert           #+#    #+#             */
/*   Updated: 2015/12/09 16:26:46 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dbl_tab.h"

static int	check_char(char shape[5][5])
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < 4)
	{
		while (++x < 4)
		{
			if (shape[y][x] != '.' && shape[y][x] != '#')
				return (0);
		}
		if (shape[y][x] != '\n')
			return (0);
		x = -1;
	}
	return (1);
}

static int	check_nb(char shape[5][5])
{
	int	x;
	int	y;
	int	nb;

	x = -1;
	y = -1;
	nb = 0;
	while (++y < 4)
	{
		while (++x < 4)
		{
			if (shape[y][x] == '#')
				nb++;
		}
		x = -1;
	}
	return (nb);
}

static int	check_shape(char shape[5][5])
{
	int	x;
	int	y;
	int	nb;

	x = -1;
	y = -1;
	nb = 0;
	while (++y < 4)
	{
		while (++x < 4)
		{
			if (shape[y][x] == '#' && shape[y][x + 1] == '#')
				nb++;
			if (shape[y][x] == '#' && shape[y + 1][x] == '#')
				nb++;
		}
		x = -1;
	}
	if (nb >= 3)
		return (1);
	return (0);
}

int		file_valide(t_tetri *tet)
{
	while (tet)
	{
		if (!check_char(tet->shape))
			return (0);
		if (check_nb(tet->shape) != 4)
			return (0);
		if (!check_shape(tet->shape))
			return (0);
		tet = tet->next;
	}
	return (1);
}
