/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:53:50 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/08 10:20:11 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dbl_tab.h"

int	check_place(char **tab, char shape[5][5], t_pnt o, int size)
{
	t_pnt	first;
	t_pnt	i;
	int		cond;
	int		check_x;
	int		check_y;

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
				check_x = o.x - first.x + i.x;
				check_y = o.y - first.y + i.y;
				if (check_x < 0 || check_y < 0)
					return (-1);
				if (check_x >= size || check_y >= size)
					return (-1);
				if (tab[check_y][check_x] != '.')
					return (0);
			}
			else if (shape[i.y][i.x] != '.')
			{
				check_x = o.x - first.x + i.x;
				check_y = o.y - first.y + i.y;
				if (check_x < 0 || check_y < 0)
					return (-1);
				if (check_x >= size || check_y >= size)
					return (-1);
				if (tab[check_y][check_x] != '.')
					return (0);
			}
			i.x = i.x + 1;
		}
		i.y = i.y + 1;
	}
	return (1);
}
