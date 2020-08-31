/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:34:17 by ciglesia          #+#    #+#             */
/*   Updated: 2019/10/14 12:48:44 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	***ident_end(char *line, char *tetro, char ***figures, int q)
{
	free(tetro);
	free(line);
	figures[q] = processing("...", -1, 1);
	if (q == 0)
		return (NULL);
	if (q == 1)
	{
		print_tetro(figures[0], ft_strlen(figures[0][0]), 0);
		free_tetros(figures);
		exit(0);
	}
	return (figures);
}

static int	verifysides(char *lines[4], int i, int j)
{
	int count;

	count = 0;
	if (i % 3 == 0)
	{
		count = (i == 0 && lines[1][j] == (char)'#') ? count + 1 : count;
		count = (i == 3 && lines[2][j] == (char)'#') ? count + 1 : count;
	}
	else
	{
		count = (lines[i + 1][j] == (char)'#') ? count + 1 : count;
		count = (lines[i - 1][j] == (char)'#') ? count + 1 : count;
	}
	if (j % 3 == 0)
	{
		count = (j == 0 && lines[i][1] == (char)'#') ? count + 1 : count;
		count = (j == 3 && lines[i][2] == (char)'#') ? count + 1 : count;
	}
	else
	{
		count = (lines[i][j + 1] == (char)'#') ? count + 1 : count;
		count = (lines[i][j - 1] == (char)'#') ? count + 1 : count;
	}
	return (count);
}

static int	tetro_split(char *tetro, int i, char *lines[4])
{
	if (ft_countchr(tetro, '#') != 4 || ft_countchr(tetro, '.') != 12 ||
		ft_strlen(tetro) != 16)
		return (0);
	while (i < 4)
	{
		lines[i] = ft_strndup(tetro + 4 * i, 4);
		i++;
	}
	return (i);
}

static int	analize(char *tetro, int unity)
{
	char	*lines[4];
	int		i;
	int		j;
	int		sides;

	if (!(i = tetro_split(tetro, 0, lines)))
		return (0);
	while (i > 0)
	{
		i--;
		j = -1;
		while (++j < 4)
		{
			if (lines[i][j] == (char)'#')
			{
				if (!(sides = verifysides(lines, i, j)))
					return (0);
				unity = (sides > 1) ? unity + 1 : unity;
			}
		}
	}
	while (i < 4)
		free(lines[i++]);
	return ((unity > 0) ? 1 : 0);
}

char		***ft_identify(int fd, int i, int q)
{
	char	*line;
	char	*tetro;
	char	***figures;

	if (!(figures = (char***)malloc(sizeof(char**) * (60))))
		return (NULL);
	if (!(tetro = ft_strnew(1)))
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		if (i < 4)
			tetro = ft_fstrjoin(tetro, line);
		if (i == 3 && !add_figure(analize(tetro, 0), &tetro, &figures, q))
			return (NULL);
		q += (i == 3) ? 1 : 0;
		i = (i + 1) % 5;
		free(line);
	}
	if (i != 4)
		return (NULL);
	close(fd);
	return (ident_end(line, tetro, figures, q));
}
