/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:07:35 by ciglesia          #+#    #+#             */
/*   Updated: 2019/10/14 12:57:08 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		add_figure(int analize, char **tetro, char ****figures, int q)
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

char	**cpy_tetro(char ***tetro, char ***mx, int *i, t_coords c)
{
	while (c.y <= *i)
	{
		ft_cpyxchr((*tetro)[*i - c.y], (*mx)[*i], '.', c.x);
		(*i)--;
	}
	return (*mx);
}

void	p_ntimes(char c, int n)
{
	while (n > 0)
	{
		ft_putchar(c);
		n--;
	}
	ft_putchar('\n');
}

void	print_tetro(char **mx, int width, int height)
{
	int size;
	int i;

	while (ft_strcmp(mx[height], "0") != 0)
		height++;
	size = (height > width) ? height : width;
	i = 0;
	while (ft_strcmp(mx[i], "0") != 0)
	{
		ft_putstr(mx[i]);
		p_ntimes('.', size - width);
		i++;
	}
	while (size > height++)
		p_ntimes('.', size);
}
