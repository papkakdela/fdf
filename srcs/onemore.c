/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onemore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:50:37 by grinko            #+#    #+#             */
/*   Updated: 2020/02/02 15:43:55 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	input3(t_read *q, int i, int j, char **strm)
{
	q->arr[j][i] = ft_atoi(strm[i]);
	if ((i + j) / 2 - q->arr[j][i] > q->maxy)
		q->maxy = (i + j) / 2 - q->arr[j][i];
	if ((i + j) / 2 - q->arr[j][i] < q->my)
		q->my = (i + j) / 2 - q->arr[j][i];
}

void	strclean(char **s, int k)
{
	int i;

	i = 0;
	while (i <= k)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	kotikitebyalubyat(t_read *q)
{
	disiserrorbitch("Error! invalid file");
	freeall((char **)q->arr);
}

void	udobnoepolojenie(t_read *q, int fb)
{
	close(fb);
	q->x = round((q->column + q->row) * q->sl + q->sl);
}

void	kuritdivan(t_read *q, char *oneline)
{
	if (*oneline)
		q->i++;
	else
		disiserrorbitch("Error! invalid file");
	free(oneline);
}
