/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_figs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 01:23:06 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/27 08:31:04 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_matrix_checkfg(t_matrix *m, int const r, int const c, int const fg)
{
	int	i;
	int	max_c;
	int max_r;
	int res;

	i = -1;
	max_c = -1;
	max_r = -1;
	res = 1;
	if (r < 0 || c < 0 || r >= m->rows || c >= m->cols)
		return (-1);
	while (++i <= 12)
		if (fg & (1 << i))
		{
			if (ft_matrix_get(m, r + i / 4, c + i % 4) > 0)
				res = 0;
			if (i / 4 > max_r)
				max_r = i / 4;
			if (i % 4 > max_c)
				max_c = i % 4;
		}
	if (r + max_r >= m->rows || c + max_c >= m->cols)
		res = -1;
	return (res);
}

int		ft_matrix_setfg(t_matrix **m, int const rc, int const fg, char const s)
{
	int	i;
	int size;

	i = -1;
	size = 4;
	while (++i <= 12)
		if (fg & (1 << i))
		{
			size--;
			ft_matrix_set(m, rc / 100 + i / 4, rc % 100 + i % 4, s);
			if (size == 0)
				break ;
		}
	return (1);
}

void	ft_matrix_delfg(t_matrix **m, int const r, int const c, int const fg)
{
	int	i;
	int	size;

	i = -1;
	size = 4;
	while (++i <= 12)
		if (fg & (1 << i))
		{
			ft_matrix_set(m, r + i / 4, c + i % 4, 0);
			size--;
			if (size == 0)
				return ;
		}
}
