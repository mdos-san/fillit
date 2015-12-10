/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 19:46:09 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/07 23:15:16 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dbl_tab.h"

void	free_double_tab(char ***atab, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		free((*atab)[i]);
		i++;
	}
	free(*atab);
	*atab = 0;
}
