/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:41:25 by ciglesia          #+#    #+#             */
/*   Updated: 2019/10/14 15:20:36 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**put_tetro(char **tetro, char **m, t_coords c, int copy)
{
	int		i;
	int		j;
	char	**mx;

	mx = (copy) ? ft_vstrdup(m, "0") : m;
	i = c.y;
	while (ft_strcmp(mx[i], "0") != 0 && tetro[i - c.y])
	{
		j = c.x;
		while (mx[i][j] && tetro[i - c.y][j - c.x])
		{
			if (mx[i][j] != '.' && tetro[i - c.y][j - c.x] != '.')
				return (endmx(copy, mx));
			if (!tetro[i - c.y][j - c.x + 1] &&
				ft_strcmp(tetro[i - c.y + 1], "0") == 0)
				return (cpy_tetro(&tetro, &mx, &i, c));
			j++;
		}
		if (!mx[i][j] && tetro[i - c.y][j - c.x])
			return (endmx(copy, mx));
		i++;
	}
	return (endmx(copy, mx));
}

static int	next_tetro(char ***tetros, int frst, char **mx, t_coords c)
{
	if (mx[c.y][c.x + 1])
		c.x++;
	else
	{
		c.x = 0;
		if (ft_strcmp(mx[c.y + 1], "0") != 0)
			c.y++;
		else
		{
			c.y = 0;
			if (frst == 0)
				expand_mx(mx);
			else
				return (0);
		}
	}
	return (put_here(tetros, frst, mx, c));
}

int			put_here(char ***tetros, int frst, char **mx, t_coords c)
{
	char	**mxcopy;
	int		bool;
	t_coords cc;

	bool = 0;
	if (ft_strcmp(tetros[frst + 1][0], "0") == 0 &&
		(put_tetro(tetros[frst], mx, c, 0)))
	{
		print_mx(mx);
		return (1);
	}
	if ((mxcopy = put_tetro(tetros[frst], mx, c, 1)))
	{
		print_mx(mxcopy);
		cc.x = 0;
		cc.y = 0;
		if ((put_here(tetros, frst + 1, mxcopy, cc)))
			bool = 1;
		ft_freesv(mxcopy, "0");
	}
	if (!bool)
		return (next_tetro(tetros, frst, mx, c));
	return (bool);
}

static char	**init_mx(int size)
{
	char	**mx;
	int		i;
	int		mx_s;

	i = 0;
	if ((int)(100.0 * ft_sqrt(size)) % 100 > 0)
		mx_s = 2 * ((int)ft_sqrt(size)) + 1;
	else
		mx_s = 2 * ((int)ft_sqrt(size));
	if (size % 2 == 1)
		mx_s++;////////
	if (!(mx = (char**)malloc(sizeof(char*) * (15 + 1))))
		return (NULL);
	while (i < mx_s)
	{
		if (!(mx[i] = ft_fillstr('.', mx_s)))
			return (NULL);
		i++;
	}
	if (!(mx[i] = ft_fillstr('0', 1)))
		return (NULL);
	return (mx);
}

int			ft_solve(char ***tetros)
{
	int		i;
	char	**mx;
	t_coords c;

	i = 0;
	while (ft_strcmp(tetros[i][0], "0") != 0)
		i++;
	mx = init_mx(i);
	c.x = 0;
	c.y = 0;
	put_here(tetros, 0, mx, c);
	ft_freesv(mx, "0");
	free_tetros(tetros);
	return (1);
}
