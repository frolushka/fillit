/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 08:28:26 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/27 08:30:46 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include "string.h"
# include "libft.h"

# define USAGE_MSG "usage: ./fillit source_file"

typedef struct		s_dlist
{
	struct s_dlist	*next;
	int				value;
}					t_dlist;

typedef struct		s_matrix
{
	char			*matrix;
	int				cols;
	int				rows;
}					t_matrix;

t_dlist				*ft_dlst_new(int const val);
int					ft_dlst_pushback(t_dlist **root, t_dlist *node);
int					ft_dlst_clear(t_dlist **root);
int					ft_dlst_size(t_dlist *root);

int					ft_matrix_checkfg(t_matrix *m, int const r, int const c,
					int const fg);
int					ft_matrix_setfg(t_matrix **m, int const rc, int const fg,
					char const s);
void				ft_matrix_delfg(t_matrix **m, int const r, int const c,
					int const fg);

t_matrix			*ft_matrix_init(int rs, int cs);
char				ft_matrix_get(t_matrix const *m, int const r, int const c);
int					ft_matrix_set(t_matrix **m, int const r, int const c,
									char const val);
void				ft_matrix_delete(t_matrix **m);
void				ft_matrix_print(t_matrix const *m);

int					read_figures(int fd, t_dlist **fgs);

int					ft_checkdel(char *tmp);
int					get_square_size(int const n);
int					find_place(t_dlist *fg, t_matrix **m, int ofs);
int					find_places(t_dlist *fg, t_matrix **m, int ofs);
int					solve(t_dlist *root);

#endif
