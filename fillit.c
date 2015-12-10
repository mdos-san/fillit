/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         :+:     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+        +#+       */
/*                                                +#+#+#+#+#+    +#+          */
/*   Created: 2015/12/08 00:35:07 by mdos-san          #+#     #+#            */
/*   Updated: 2015/12/09 17:28:14 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dbl_tab.h"

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
