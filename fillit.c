/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:26:58 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/10 18:32:01 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	fillit(char **tab, int size, t_tetri *tet)
{
	t_pnt	pnt;

	pnt.x = 0;
	pnt.y = 0;
	if (!tet)
		return (1);
	while (pnt.y < size)
	{
		if (check_place(tab, tet->shape, pnt, size) > 0)
		{
			add_tetrimino(tab, tet->shape, pnt, tet->letter);
			if (fillit(tab, size, tet->next))
				return (1);
			add_tetrimino(tab, tet->shape, pnt, '.');
		}
		pnt.x++;
		if (pnt.x == size)
		{
			pnt.x = 0;
			pnt.y++;
		}
	}
	return (0);
}
