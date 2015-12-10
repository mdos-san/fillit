/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_double_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:20:16 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/10 18:32:01 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

char	**create_double_tab(int size, char c)
{
	int		i;
	char	**result;

	i = 0;
	result = (char**)malloc(sizeof(char**) * (size + 1));
	if (!result)
		return (0);
	result[size] = 0;
	while (i < size)
	{
		result[i] = (char*)malloc(size + 1);
		if (!result[i])
			return (0);
		result[i][size] = 0;
		i++;
	}
	init_double_tab(result, size, c);
	return (result);
}
