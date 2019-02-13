/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:45:09 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/27 08:31:09 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** 										|1|1|1|0|0|0|0|0|0|0|0|0|0|
**										|2|1|0|9|8|7|6|5|4|3|2|1|0|
**
**	15 - horizontal stick				|0|0|0|0|0|0|0|0|0|1|1|1|1|
**	116 - horizontal mirror Г			|0|0|0|0|0|0|1|1|1|0|1|0|0|
**	114 - horizontal T up-down			|0|0|0|0|0|0|1|1|1|0|0|1|0|
**	51 - cube							|0|0|0|0|0|0|0|1|1|0|0|1|1|
**	54 - horizontal 4					|0|0|0|0|0|0|0|1|1|0|1|1|0|
**	71 - horizontal Г					|0|0|0|0|0|0|1|0|0|0|1|1|1|
**	99 - horizontal mirror 4			|0|0|0|0|0|0|1|1|0|0|0|1|1|
**  113 - horizontal Г up-down			|0|0|0|0|0|0|1|1|1|0|0|0|1|
**	39 - horizontal T					|0|0|0|0|0|0|0|1|0|0|1|1|1|
**	23 - horizontal mirrir Г up-down	|0|0|0|0|0|0|0|0|1|0|1|1|1|
**	785 - vertical Г up-down			|0|0|0|1|1|0|0|0|1|0|0|0|1|
**	305 - left T						|0|0|0|0|1|0|0|1|1|0|0|0|1|
**	306 - vertical mirror 4				|0|0|0|0|1|0|0|1|1|0|0|1|0|
**	802 - vertical mirror Г up-down		|0|0|0|1|1|0|0|1|0|0|0|1|0|
**	561 - vertical 4					|0|0|0|1|0|0|0|1|1|0|0|0|1|
**	562 - right T						|0|0|0|1|0|0|0|1|1|0|0|1|0|
**	547 - vertical mirror Г				|0|0|0|1|0|0|0|1|0|0|0|1|1|
**	275 - vertical Г					|0|0|0|0|1|0|0|0|1|0|0|1|1|
**	4369 - vertical stick				|1|0|0|0|1|0|0|0|1|0|0|0|1|
*/

/*
** 	Проверяет тип фигуры (наличие ее хэша в списке корректных фигур).
**	Возвращаемое значение:	0, если фигура некорректна.
**						  	1, если фигура корректна.
*/

static int	check_figure(int fg)
{
	return (fg == 15 || fg == 116 || fg == 114 || fg == 51
			|| fg == 54 || fg == 71 || fg == 99 || fg == 113
			|| fg == 39 || fg == 23 || fg == 785 || fg == 305
			|| fg == 306 || fg == 802 || fg == 561 || fg == 562
			|| fg == 547 || fg == 275 || fg == 4369);
}

/*
** 	Считает хэш фигуры на основе строки str. Хэш высчитывается по формуле,
**	которую аккуратно вывел Мася потными прогерскими вечерами :3
**	Возвращаемое значение:	хэш фигуры.
**
**	От Ильи, выступающего в роли редактора:
**		"Мася", по сути, сделал ф-цию, записывающую фигуру в 12 бит, начиная
**		с первого встреченного символа "#", а я, в свою очередь, вдохнул
**		в нее жизнь.
*/

static int	get_hash(char const *str)
{
	int	res;
	int	fo;
	int	i;
	int	minx;

	res = 0;
	fo = -1;
	i = -1;
	minx = 3;
	while (++i < 16)
	{
		if (str[i] == '#')
		{
			if ((i % 4) < minx)
				minx = i % 4;
			if (fo == -1)
				fo = i;
			res += 1 << (i - fo + (fo % 4));
		}
	}
	res = res >> minx;
	return (res);
}

/*
** 	Пытается считать фигуру из файла, заданную по шаблону.
**	Шаблон представляет из себя фигуру размером 4 на 4.
**	В случае нарушения шаблона выдает ошибку.
**	Возвращаемое значение:	1, если чтение прошло без ошибок.
**							0, если возникли ошибки.
*/

static int	read_block(int fd, char **block)
{
	int		i1;
	int		i2;
	char	*tmp;

	i1 = -1;
	if (!(*block = (char *)ft_memalloc(17)))
		return (0);
	while (++i1 < 4)
	{
		if (get_next_line(fd, &tmp) < 1 || ft_strlen(tmp) != 4)
			return (ft_checkdel(tmp));
		i2 = -1;
		while (++i2 < 4)
			if (tmp[i2] != '#' && tmp[i2] != '.')
				return (ft_checkdel(tmp));
		ft_strcat(*block, tmp);
		free(tmp);
		tmp = NULL;
	}
	return (1);
}

/*
** 	Создает новую вершину t_dlist на основе считанного блока из read_block,
**	после чего записывает ее по адресу fig. Если после блока в файле не стоит
**	символ '\n' или EOF, выдает ошибку.
**	Возвращаемое значение:	-1, если произошла ошибка чтения.
**							0, если чтение прошло без ошибок и EOF.
**							1, если чтение прошло без ошибок и не EOF.
*/

static int	read_figure(int fd, t_dlist **fig)
{
	int		hash;
	int		sts;
	char	*block;

	block = NULL;
	if (!read_block(fd, &block))
	{
		if (block)
			free(block);
		return (-1);
	}
	hash = get_hash(block);
	free(block);
	if (!check_figure(hash))
		return (-1);
	*fig = ft_dlst_new(hash);
	sts = get_next_line(fd, &block);
	if (sts == 1 && *block)
		sts = -1;
	if (sts != 0 && block)
		free(block);
	return (sts);
}

/*
** 	Считывает список фигур из файла, заданного дескриптором fd.
**	Возвращаемое значение:	0, если чтение прошло без ошибок.
**							-1, если во время чтения файла возникли ошибки.
*/

int			read_figures(int fd, t_dlist **fgs)
{
	t_dlist	*tmp;
	int		sts;
	int		size;

	tmp = NULL;
	size = 0;
	while ((sts = read_figure(fd, &tmp)) != 0)
	{
		if (sts < 0 || ++size > 26 || !tmp)
		{
			close(fd);
			if (tmp)
				free(tmp);
			return (-1);
		}
		ft_dlst_pushback(fgs, tmp);
		tmp = NULL;
	}
	ft_dlst_pushback(fgs, tmp);
	close(fd);
	return (0);
}
