/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:21:49 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/01 01:24:39 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_mx(char **mx)
{
	int i;

	i = 0;
	while (ft_strcmp(mx[i], "0") != 0)
		ft_putendl(mx[i++]);
}

int		expand_mx(char **mx)
{
	int i;

	i = 0;
	while (ft_strcmp(mx[i], "0") != 0)
	{
		mx[i] = ft_fstrjoin(mx[i], ".");
		i++;
	}
	free(mx[i]);
	if (!(mx[i] = ft_fillstr('.', ft_strlen(mx[i - 1]))))
		return (0);
	if (!(mx[i + 1] = ft_fillstr('0', 1)))
		return (0);
	return (1);
}

void	free_tetros(char ***tetros)
{
	int i;
	int j;

	i = 0;
	while (ft_strcmp(tetros[i][0], "0") != 0)
	{
		j = 0;
		while (ft_strcmp(tetros[i][j], "0") != 0)
		{
			free(tetros[i][j]);
			j++;
		}
		free(tetros[i][j]);
		free(tetros[i]);
		i++;
	}
	ft_freesv(tetros[i], "0");
	free(tetros);
}

char	**crop_tetro(char *tetro, int a, int h[2], int v[2])
{
	int		i;
	char	**res;
	int		zro;

	zro = (a < 0) ? 1 : 0;
	if (!(res = (char**)malloc(sizeof(char*) * ft_abs((v[1] - v[0] + 2)))))
		return (NULL);
	i = 0;
	while (i < 4 && i <= (v[1] - v[0]) && !zro)
	{
		res[i] = ft_strndup((tetro + h[0] + v[0] * 4)
							+ 4 * i, h[1] - h[0] + 1);
		ft_chgchr(res[i], '#', (char)(a + 65));
		i++;
	}
	if (!(res[i] = ft_strdup("0")))
		return (NULL);
	return (res);
}

char	**processing(char *tetro, int a, int zro)
{
	int horiz[2];
	int vert[2];
	int i;

	horiz[0] = 3;
	horiz[1] = 0;
	vert[0] = (!zro) ? 3 : 0;
	vert[1] = 0;
	i = 0;
	while (tetro[i] && !zro)
	{
		if (tetro[i] == (char)'#')
		{
			if (i % 4 < horiz[0])
				horiz[0] = i % 4;
			if (i % 4 > horiz[1])
				horiz[1] = i % 4;
			if ((int)(i / 4) < vert[0])
				vert[0] = ((int)(i / 4));
			if ((int)(i / 4) > vert[1])
				vert[1] = ((int)(i / 4));
		}
		i++;
	}
	return (crop_tetro(tetro, a, horiz, vert));
}
