/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_tab.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:20:20 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/09 17:19:56 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DBL_TAB_H
# define DBL_TAB_H

typedef struct		s_pnt
{
	int				x;
	int				y;
}					t_pnt;

typedef struct		s_tetri
{
	char			shape[5][5];
	char			letter;
	struct s_tetri	*next;
}					t_tetri;

char				**create_double_tab(int size, char c);
void				init_double_tab(char **tab, int size, char c);
void				display_double_tab(char **tab, int size);
void				add_tetrimino(char **tab, char shape[5][5], t_pnt o, char c);
int					check_place(char **tab, char shape[5][5], t_pnt o, int size);
void				free_double_tab(char ***atab, int size);
t_tetri				*tetri_new(char c);
void				tetri_add(t_tetri *tet);
int					tetri_count(t_tetri *tet);
int					init_shape(t_tetri *tet, int fd);
int					fillit(char **tab, int size, t_tetri *tet);
int					ft_sqrt(int nb);
int					file_valide(t_tetri *tet);

#endif
