/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:56:21 by grinko            #+#    #+#             */
/*   Updated: 2020/02/02 14:49:06 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		color3(int code, t_read *a)
{
	if (code == 24)
		a->sl += 1;
	if (code == 26)
	{
		a->fi = 0xf4feff;
		a->se = 0xf0749e;
	}
	if (code == 28)
	{
		a->fi = 0xb5bba4;
		a->se = 0x00b349;
	}
	if (code == 25)
	{
		a->fi = 0x5586a6;
		a->se = 0x9a270c;
	}
}

void		color2(int code, t_read *a)
{
	if (code == 18)
	{
		a->fi = 0x936CD6;
		a->se = 0xFFCA40;
	}
	if (code == 19)
	{
		a->fi = 0xFB3F51;
		a->se = 0xABF000;
	}
	if (code == 20)
	{
		a->fi = 0xD21101;
		a->se = 0x5941CD;
	}
	if (code == 21)
	{
		a->fi = 0x416C5A;
		a->se = 0x9E935F;
	}
	if (code == 22)
	{
		a->fi = 0x961F1C;
		a->se = 0xFFF542;
	}
}

void		color1(int code, t_read *a)
{
	if (code == 83)
		a->pepe = 1;
	if (code == 84)
		a->pepe = 2;
	if (code == 32)
		a->amp += 0.05;
	if (code == 27)
		a->sl -= 1;
	if (code == 29)
	{
		a->fi = 0x00FFFF;
		a->se = 0xFF6347;
	}
	if (code == 23)
	{
		a->fi = 0x9E935F;
		a->se = 0xE28898;
	}
	if (code >= 18 && code <= 22)
		color2(code, a);
	if (code >= 24 && code <= 28)
		color3(code, a);
}

int			pkey(int code, void *param)
{
	t_read *a;

	a = param;
	if (code == 53)
		exit(0);
	if (code == 12)
		a->angl += 5;
	if (code == 13)
		a->angl -= 5;
	if (code == 2)
		a->amp -= 0.05f;
	if (code == 126)
		a->movy -= 10;
	if (code == 125)
		a->movy += 10;
	if (code == 124)
		a->movx += 10;
	if (code == 123)
		a->movx -= 10;
	if ((code <= 32 && code >= 18) || code == 83 || code == 84)
		color1(code, a);
	mlx_clear_window(a->ini, a->win);
	printmap(a);
	return (0);
}

int			main(int argc, char **argv)
{
	int		fb;
	t_read	*q;

	if (argc != 2)
		disiserrorbitch("Error! You need: ./fdf <filename>\n");
	if ((fb = open(argv[1], O_RDONLY)) < 0)
		disiserrorbitch("Error! No file be found");
	q = create_read();
	inputread(q, argv[1], fb);
	q->ini = mlx_init();
	q->win = mlx_new_window(q->ini, 1000, 1000, "love ur a$$");
	create_map(q);
	mlx_key_hook(q->win, pkey, (void*)q);
	printmap(q);
	mlx_loop(q->ini);
	free(q);
	return (0);
}
