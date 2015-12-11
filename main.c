/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:20:29 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/11 15:18:14 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"
#include "libft.h"

void	print_error(void)
{
	ft_putendl("error");
	exit(0);
}

void	end_fillit(char ***tab, int size, int fd)
{
	display_double_tab(*tab, size);
	free_double_tab(tab, size);
	close(fd);
}

int		main(int ac, char **av)
{
	int		fd;
	char	**tab;
	int		size;
	t_tetri *tet;

	fd = 0;
	tet = tetri_new('A');
	if (ac != 2)
		print_error();
	fd = open(av[1], O_RDONLY);
	(fd == -1) ? print_error() : 0;
	init_shape(tet, fd);
	if (!file_valide(tet))
		print_error();
	size = ft_sqrt(tetri_count(tet) * 4);
	tab = create_double_tab(size, '.');
	while (fillit(tab, size, tet) == 0)
	{
		free_double_tab(&tab, size);
		size++;
		tab = create_double_tab(size, '.');
	}
	end_fillit(&tab, size, fd);
	return (0);
}
