/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tetrimino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:20:07 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/09 17:22:06 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dbl_tab.h"

void	add_tetrimino(char **tab, char shape[5][5], t_pnt o, char c)
{
	t_pnt	first;
	t_pnt	i;
	int		cond;

	i.y = 0;
	cond = 0;
	while (i.y < 4)
	{
		i.x = 0;
		while (i.x < 4)
		{
			if (cond == 0 && shape[i.y][i.x] != '.')
			{
				first.x = i.x;
				first.y = i.y;
				cond = 1;
				tab[o.y + i.y - first.y][o.x + i.x - first.x] = c;
			}
			else if (shape[i.y][i.x] != '.')
				tab[o.y + i.y - first.y][o.x + i.x - first.x] = c;
			i.x = i.x + 1;
		}
		i.y = i.y + 1;
	}
}
