/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:56:41 by grinko            #+#    #+#             */
/*   Updated: 2020/02/02 15:44:08 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		eq(int x, float k, int b)
{
	return (round(x * k) + b);
}

int		req(int y, float k, int b)
{
	return (round((y - b) / k));
}

void	prl(t_nod *f, t_nod *s, t_read *q, int sc)
{
	q->s = 1;
	q->k = (float)((rety(s, q) - q->my * q->sl) - (rety(f, q) - q->my \
	* q->sl)) / (float)(((retx(s, q) + sc) - (retx(f, q) + sc)));
	q->b = (rety(f, q) - q->my * q->sl) - q->k * (retx(f, q) + sc);
	if ((retx(f, q) + sc) == (retx(s, q) + sc))
	{
		q->xo = (rety(f, q) - q->my * q->sl);
		if ((rety(f, q) - q->my * q->sl) > (rety(s, q) - q->my * q->sl))
			q->s = -1;
		while (q->xo != (rety(s, q) - q->my * q->sl))
		{
			mlx_pixel_put(q->ini, q->win, (retx(f, q) + sc), q->xo, q->fi);
			q->xo += q->s;
		}
		return ;
	}
	if (fabs(q->k) > 1)
		prl2(q, f, s);
	else
		prl3(q, f, s, sc);
}

void	prl2(t_read *q, t_nod *f, t_nod *s)
{
	q->xo = (rety(f, q) - q->my * q->sl);
	if (q->xo > (rety(s, q) - q->my * q->sl))
		q->s = -1;
	while (q->xo != (rety(s, q) - q->my * q->sl))
	{
		mlx_pixel_put(q->ini, q->win, req(q->xo, q->k, q->b), q->xo, q->fi);
		q->xo += q->s;
	}
}

void	prl3(t_read *q, t_nod *f, t_nod *s, int sc)
{
	q->xo = (retx(f, q) + sc);
	if (q->xo > (retx(s, q) + sc))
		q->s = -1;
	while (q->xo != (retx(s, q) + sc))
	{
		mlx_pixel_put(q->ini, q->win, q->xo, eq(q->xo, q->k, q->b), q->se);
		q->xo += q->s;
	}
}
