/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:56:50 by grinko            #+#    #+#             */
/*   Updated: 2020/02/02 15:42:24 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	freeall(char **freesmth)
{
	int i;

	i = 0;
	while (freesmth[i])
	{
		free(freesmth[i]);
		i++;
	}
	free(freesmth);
}

void	disiserrorbitch(char *str)
{
	ft_putstr(str);
	exit(0);
}

t_read	*create_read(void)
{
	t_read *a;

	a = (t_read*)malloc(sizeof(t_read));
	a->maxy = 0;
	a->my = 2000;
	a->angl = 0;
	a->sl = 10;
	a->amp = 1;
	a->movx = 0;
	a->movy = 0;
	a->fi = 0xeb3b88;
	a->se = 16777215;
	a->i = 0;
	a->j = 0;
	a->pepe = 1;
	return (a);
}

void	inputread(t_read *q, char *file, int fb)
{
	char	*oneline;
	char	**strm;

	q->i = 0;
	if (!(get_next_line(fb, &oneline)))
		disiserrorbitch("Error! invalid file");
	if (!(strm = ft_strsplit(oneline, ' ')))
		disiserrorbitch("Error! invalid file");
	free(oneline);
	while (strm[q->i])
		q->i++;
	freeall(strm);
	q->column = q->i;
	q->i = 1;
	while (get_next_line(fb, &oneline) > 0)
		kuritdivan(q, oneline);
	q->row = q->i;
	if (!(q->arr = (int **)malloc(sizeof(int *) * q->row)))
		disiserrorbitch("No map!");
	q->i = 0;
	close(fb);
	input2(q, file, fb, strm);
}

void	input2(t_read *q, char *file, int fb, char **strm)
{
	char	*oneline;
	int		count;
	int		i;
	int		j;

	count = -1;
	fb = open(file, O_RDONLY);
	while (++count < q->row)
		q->arr[count] = (int *)malloc(sizeof(int) * q->column);
	j = 0;
	while (get_next_line(fb, &oneline) > 0)
	{
		strm = ft_strsplit(oneline, ' ');
		i = -1;
		free(oneline);
		while (strm[++i])
			input3(q, i, j, strm);
		j++;
		strclean(strm, q->column);
		if (i != q->column)
			kotikitebyalubyat(q);
	}
	udobnoepolojenie(q, fb);
}
