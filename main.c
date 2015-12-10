/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:20:29 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/09 17:16:01 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "dbl_tab.h"
#include "libft.h"

int	main(int ac, char **av)
{
	int		fd;
	char	**tab;
	int		size;
	t_tetri *tet;

	fd = 0;
	tet = tetri_new('A');
	if (ac != 2)
	{
		ft_putendl("error");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	init_shape(tet, fd);
	if (!file_valide(tet))
	{
		ft_putendl("error");
		return (0);
	}
	size = ft_sqrt(tetri_count(tet) * 4);
	tab = create_double_tab(size, '.');
	while (fillit(tab, size, tet) == 0)
	{
		free_double_tab(&tab, size);
		size++;
		tab = create_double_tab(size, '.');
	}
	display_double_tab(tab, size);
	free_double_tab(&tab, size);
	close(fd);
	return (0);
}
