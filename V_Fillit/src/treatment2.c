/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:07:35 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/01 01:31:11 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	add_figure(int analize,	char **tetro, char ****figures, int q)
{
	if (!analize)
	{
		free(*figures);
		return (0);
	}
	(*figures)[q] = processing(*tetro, q, 0);
	free(*tetro);
	if (!(*tetro = ft_strnew(1)))
		return (0);
	return (1);
}

char	**endmx(int copy, char **mx)
{
	if (copy)
		ft_freesv(mx, "0");
	return (NULL);
}

char 	**cpy_tetro(char ***tetro, char ***mx, int *i, t_coords c)
{
	while (c.y <= *i)
	{
		ft_cpyxchr((*tetro)[*i - c.y], (*mx)[*i], '.', c.x);
		(*i)--;
	}
	return (*mx);
}

void	init_color(char c)
{
	char str[20];

	c *= 97;
	c = ft_abs(c % 100);
	str[0] = '\e';
	str[1] = '[';
	str[2] = '3';
	str[3] = '8';
	str[4] = ';';
	str[5] = '2';
	str[6] = ';';
	str[7] = c % 8 + 48;
	str[8] = c / 10 + 48;
	str[9] = c % 10 + 48;
	str[10] = ';';
	str[11] = c % 7 + 48;
	str[12] = c % 10 + 48;
	str[13] = c / 10 + 48;
	str[14] = ';';
	str[15] = c % 10 + 48;
	str[16] = c / 10 + 48;
	str[17] = c % 10 + 48;
	str[18] = 'm';
	str[19] = '\0';
	write(1, str, 20);
}
