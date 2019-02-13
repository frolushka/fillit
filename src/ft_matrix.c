/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 01:14:54 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/27 08:31:06 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_matrix		*ft_matrix_init(int rs, int cs)
{
	t_matrix	*res;

	if (rs <= 0 || cs <= 0 || !(res = (t_matrix *)malloc(sizeof(res))))
		return (NULL);
	if (!(res->matrix = ft_memalloc(rs * cs)))
	{
		ft_matrix_delete(&res);
		return (NULL);
	}
	res->rows = rs;
	res->cols = cs;
	return (res);
}

char			ft_matrix_get(t_matrix const *m, int const r, int const c)
{
	int	rs;
	int	cs;

	if (!m)
		return (-1);
	rs = m->rows;
	cs = m->cols;
	if (r >= rs || c >= cs)
		return (-1);
	return (m->matrix[(r * cs + c)]);
}

int				ft_matrix_set(t_matrix **m, int const r, int const c,
								char const val)
{
	int	rs;
	int	cs;

	if (!m || !*m)
		return (-1);
	rs = (*m)->rows;
	cs = (*m)->cols;
	if (r >= rs || c >= cs)
		return (-1);
	(*m)->matrix[(r * cs + c)] = val;
	return (0);
}

void			ft_matrix_delete(t_matrix **m)
{
	if (!m || !*m)
		return ;
	if ((*m)->matrix)
		free((*m)->matrix);
	free(*m);
	*m = NULL;
}

void			ft_matrix_print(t_matrix const *m)
{
	int		i;
	int		rs;
	int		cs;
	char	tmp;

	if (!m)
		return ;
	rs = m->rows;
	cs = m->cols;
	i = -1;
	while (++i < rs * cs)
	{
		tmp = ft_matrix_get(m, i / cs, i % cs);
		ft_putchar(tmp > 0 ? tmp : '.');
		if (i % cs == cs - 1)
			ft_putchar('\n');
	}
}
