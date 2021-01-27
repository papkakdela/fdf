/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:57:08 by grinko            #+#    #+#             */
/*   Updated: 2020/02/02 15:42:55 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>

# define R 0.01745329

typedef struct		s_nod
{
	int				x;
	int				y;
	int				z;
	struct s_nod	*r;
	struct s_nod	*d;
	struct s_nod	*nxt;
	struct s_nod	*str;
}					t_nod;

typedef struct		s_read
{
	void			*ini;
	void			*win;
	int				column;
	int				row;
	int				**arr;
	t_nod			*nod;
	int				x;
	int				maxy;
	int				my;
	int				sl;
	int				angl;
	float			amp;
	int				movx;
	int				movy;
	int				dcol;
	int				ucol;
	int				fi;
	int				se;
	int				i;
	int				j;
	int				b;
	int				xo;
	int				s;
	float			k;
	int				pepe;
}					t_read;

void				create_map(t_read *q);
t_nod				*n_cr(int x, int y, int z);
t_read				*create_read();
void				printmap(t_read *f);
void				input2(t_read *q, char *file, int fb, char **strm);
void				prl(t_nod *f, t_nod *s, t_read *q, int sc);
void				inputread(t_read *q, char *file, int fb);
void				disiserrorbitch(char *str);
void				freeall(char **freesmth);
int					retx(t_nod *a, t_read *b);
int					rety(t_nod *a, t_read *b);
void				window(t_read *a);
void				smallsquares(t_read *a, int x, int y, int color);
void				sqpaint(t_read *a);
void				color1(int code, t_read *a);
void				color2(int code, t_read *a);
void				color3(int code, t_read *a);
int					pkey(int code, void *param);
void				window2(t_read *a);
t_nod				*piupiu(t_nod *cur, t_read *q);
void				prl2(t_read *q, t_nod *f, t_nod *s);
void				prl3(t_read *q, t_nod *f, t_nod *s, int sc);
int					eq(int x, float k, int b);
int					req(int y, float k, int b);
void				input3(t_read *q, int i, int j, char **strm);
void				strclean(char **s, int k);
void				kotikitebyalubyat(t_read *q);
void				udobnoepolojenie(t_read *q, int fb);
void				kuritdivan(t_read *q, char *oneline);

#endif
