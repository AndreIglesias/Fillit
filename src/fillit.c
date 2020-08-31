/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:59:22 by ciglesia          #+#    #+#             */
/*   Updated: 2019/10/14 12:10:52 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_validdoc(int fd)
{
	char	*line;
	int		i;
	int		len;
	int		q;
	int		tetro;

	i = 0;
	tetro = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tetro = (i == 0) ? tetro + 1 : tetro;
		i = (i + 1) % 5;
		len = ft_strlen(line);
		q = ft_countchr(line, '#') + ft_countchr(line, '.');
		if ((len != q) || ((len != 4) && (len != 0)) ||
			((i == 0) && (len != 0)) || ((i != 0) && (len == 0)) || tetro > 26)
		{
			free(line);
			return (0);
		}
		free(line);
	}
	free(line);
	close(fd);
	return (1);
}

static int		closedoc(char *str, int fd)
{
	ft_putendl(str);
	close(fd);
	return (-1);
}

int				main(int argc, char **argv)
{
	int		fd;
	char	guacal[1];
	char	***tetros;

	if (argc == 2)
	{
		if (!(fd = open(argv[1], O_RDONLY)))
			return (-1);
		if (fd < 0 || read(fd, guacal, 0) || (!ft_validdoc(fd)))
			return (closedoc("error", fd));
		if (!(fd = open(argv[1], O_RDONLY)))
			return (-1);
		if (!(tetros = ft_identify(fd, 0, 0)))
			return (closedoc("error", fd));
		if ((!ft_solve(tetros)))
			return (closedoc("error", fd));
	}
	else
		ft_putendl("Invalid number of arguments!");
	return (0);
}
