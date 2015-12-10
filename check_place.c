/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:53:50 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/10 18:15:40 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dbl_tab.h"

static int	fcheck(t_pnt *check, t_pnt *first, t_pnt *i, t_pnt *o)
{
	check->x = o->x - first->x + i->x;
	check->y = o->y - first->y + i->y;
	return (1);
}

static void	assign_first(t_pnt *check, t_pnt *first, t_pnt *i, t_pnt *o)
{
	first->x = i->x;
	first->y = i->y;
	fcheck(check, first, i, o);
}

static int	return_fnt(char **tab, t_pnt check, int size)
{
	if (check.x < 0 || check.y < 0)
		return (0);
	if (check.x >= size || check.y >= size)
		return (0);
	if (tab[check.y][check.x] != '.')
		return (0);
	return (1);
}

int			check_place(char **tab, char shape[5][5], t_pnt o, int size)
{
	t_pnt	i;
	t_pnt	first;
	t_pnt	check;
	int		cond;

	i.y = -1;
	cond = 0;
	while (++i.y < 4)
	{
		i.x = -1;
		while (++i.x < 4)
			if (cond == 0 && shape[i.y][i.x] != '.')
			{
				cond++;
				assign_first(&check, &first, &i, &o);
				if (!return_fnt(tab, check, size))
					return (0);
			}
			else if (shape[i.y][i.x] != '.' && fcheck(&check, &first, &i, &o))
				if (!return_fnt(tab, check, size))
					return (0);
	}
	return (1);
}
