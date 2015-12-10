/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:32:16 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/10 18:32:01 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

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
