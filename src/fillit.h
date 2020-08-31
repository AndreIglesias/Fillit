/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:59:02 by ciglesia          #+#    #+#             */
/*   Updated: 2019/10/14 12:47:37 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_coords
{
	int				x;
	int				y;
}					t_coords;

int					put_here(char ***tetros, int frst, char **mx, t_coords c);
char				***ft_identify(int fd, int i, int q);
int					ft_solve(char ***tetros);
void				print_mx(char **mx);
void				print_tetro(char **mx, int width, int height);
int					expand_mx(char **mx);
void				free_tetros(char ***tetros);
char				**crop_tetro(char *tetro, int a, int h[2], int v[2]);
char				**processing(char *tetro, int a, int zro);
int					add_figure(int analize, char **tetro,
								char ****figures, int q);
char				**endmx(int copy, char **mx);
char				**cpy_tetro(char ***tetro, char ***mx, int *i, t_coords c);

#endif
