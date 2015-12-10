/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         :+:     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+        +#+       */
/*                                                +#+#+#+#+#+    +#+          */
/*   Created: 2015/12/07 23:25:38 by mdos-san          #+#     #+#            */
/*   Updated: 2015/12/08 02:52:10 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dbl_tab.h"

t_tetri	*tetri_new(char c)
{
	t_tetri	*new;

	new = (t_tetri*)malloc(sizeof(t_tetri));
	if (!new)
		return (0);
	new->next = 0;
	new->letter = c;
	return (new);
}
