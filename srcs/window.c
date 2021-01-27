/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:56:28 by grinko            #+#    #+#             */
/*   Updated: 2020/02/02 14:35:18 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	window(t_read *a)
{
	mlx_string_put(a->ini, a->win, 800, 10, 0xDEEDD3, "NAVIGATION");
	mlx_string_put(a->ini, a->win, 700, 30, 0xDEEDD3,\
	"Click <- ^ ->to move Map");
	mlx_string_put(a->ini, a->win, 700, 60, 0xDEEDD3,\
	"Use + to make Bigger");
	mlx_string_put(a->ini, a->win, 700, 90, 0xDEEDD3,\
	"Use - to make Smaller");
	mlx_string_put(a->ini, a->win, 640, 120, 0xDEEDD3,\
	"Use 'U' to up the level of heihts");
	mlx_string_put(a->ini, a->win, 640, 150, 0xDEEDD3,\
	"Use 'D' to down the level of heihts");
	mlx_string_put(a->ini, a->win, 640, 180, 0xDEEDD3,\
	"Use 'Q' and 'W' to spin the Map");
	mlx_string_put(a->ini, a->win, 400, 900, 0xDEEDD3,\
	"ALSO You can change color");
	window2(a);
	sqpaint(a);
}

void	window2(t_read *a)
{
	mlx_string_put(a->ini, a->win, 640, 210, 0xDEEDD3,\
	"You can change type of projections");
	mlx_string_put(a->ini, a->win, 690, 240, 0xDEEDD3,\
	"click 1 or click 2 on numpad");
	mlx_string_put(a->ini, a->win, 40, 968, 0xedf3fe, "0");
	mlx_string_put(a->ini, a->win, 130, 968, 0xedf3fe, "1");
	mlx_string_put(a->ini, a->win, 210, 968, 0xedf3fe, "2");
	mlx_string_put(a->ini, a->win, 300, 968, 0xedf3fe, "3");
	mlx_string_put(a->ini, a->win, 380, 968, 0xedf3fe, "4");
	mlx_string_put(a->ini, a->win, 460, 968, 0xedf3fe, "5");
	mlx_string_put(a->ini, a->win, 540, 968, 0xedf3fe, "6");
	mlx_string_put(a->ini, a->win, 620, 968, 0xedf3fe, "7");
	mlx_string_put(a->ini, a->win, 700, 968, 0xedf3fe, "8");
	mlx_string_put(a->ini, a->win, 780, 968, 0xedf3fe, "9");
}

void	sqpaint(t_read *a)
{
	smallsquares(a, 20, 960, 0x00FFFF);
	smallsquares(a, 20, 980, 0xFF6347);
	smallsquares(a, 110, 960, 0x936CD6);
	smallsquares(a, 110, 980, 0xFFCA40);
	smallsquares(a, 190, 960, 0xFB3F51);
	smallsquares(a, 190, 980, 0xABF000);
	smallsquares(a, 270, 960, 0xD21101);
	smallsquares(a, 270, 980, 0x5941CD);
	smallsquares(a, 350, 960, 0x416C5A);
	smallsquares(a, 350, 980, 0x9E935F);
	smallsquares(a, 430, 960, 0x9E935F);
	smallsquares(a, 430, 980, 0xE28898);
	smallsquares(a, 510, 960, 0x961F1C);
	smallsquares(a, 510, 980, 0xFFF542);
	smallsquares(a, 590, 960, 0xf4feff);
	smallsquares(a, 590, 980, 0xf0749e);
	smallsquares(a, 670, 960, 0xb5bba4);
	smallsquares(a, 670, 980, 0x00b349);
	smallsquares(a, 750, 960, 0x5586a6);
	smallsquares(a, 750, 980, 0x9a270c);
}

void	smallsquares(t_read *a, int x, int y, int color)
{
	int i;
	int j;
	int o;

	i = 0;
	j = 0;
	o = x;
	while (i < 10)
	{
		j = 0;
		x = o;
		y++;
		while (j < 10)
		{
			mlx_pixel_put(a->ini, a->win, x, y, color);
			j++;
			x++;
		}
		i++;
	}
}

t_nod	*piupiu(t_nod *cur, t_read *q)
{
	cur->r = n_cr(q->j * 1, q->i * 1, q->arr[q->i][q->j] * 1);
	cur = cur->r;
	return (cur);
}
