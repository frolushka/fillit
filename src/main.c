/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:14:17 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/27 08:31:20 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"

int	main(int argc, char **argv)
{
	t_dlist	*fgs;
	int		fd;

	fgs = NULL;
	if (argc != 2)
	{
		ft_putendl(USAGE_MSG);
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) <= 0
		|| read_figures(fd, &fgs) != 0
		|| solve(fgs) != 0)
		ft_putendl("error");
	ft_dlst_clear(&fgs);
	return (0);
}
