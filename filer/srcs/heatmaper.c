/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmaper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <tbrizon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 12:07:42 by tbrizon           #+#    #+#             */
/*   Updated: 2019/09/11 11:03:01 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		last_check(t_filler *filler)
{
	int y;
	int x;

	y = -1;
	x = -1;
	while (++y < filler->m_ymax)
	{
		while (++x < filler->m_xmax)
		{
			if (filler->hmap[y][x] == 0)
				filler->hmap[y][x] = 20;
		}
		x = -1;
	}
}

int				check(t_filler *filler, int y, int x)
{
	if (x < filler->m_xmax && y < filler->m_ymax
		&& x >= 0 && y >= 0 && filler->hmap[y][x] == 0)
		return (1);
	return (0);
}

static int		plague(t_filler *filler, int x, int y, int i)
{
	int flags;

	flags = 0;
	if (check(filler, y, x + 1) && (flags += 1))
		filler->hmap[y][x + 1] = i + 1;
	if (check(filler, y + 1, x + 1) && (flags += 1))
		filler->hmap[y + 1][x + 1] = i + 1;
	if (check(filler, y - 1, x + 1) && (flags += 1))
		filler->hmap[y - 1][x + 1] = i + 1;
	if (check(filler, y - 1, x) && (flags += 1))
		filler->hmap[y - 1][x] = i + 1;
	if (check(filler, y + 1, x) && (flags += 1))
		filler->hmap[y + 1][x] = i + 1;
	if (check(filler, y, x - 1) && (flags += 1))
		filler->hmap[y][x - 1] = i + 1;
	if (check(filler, y + 1, x - 1) && (flags += 1))
		filler->hmap[y + 1][x - 1] = i + 1;
	if (check(filler, y - 1, x - 1) && (flags += 1))
		filler->hmap[y - 1][x - 1] = i + 1;
	return (flags);
}

/*
** RECUSRIVE FOUNCTION WHO SPREAD THE VALUE OF THE
** ENEMY (1) BY INCREMENTATION (+1) WITH THE FOUNCTION PLAGUE.
*/

static int		plague_hmp(t_filler *filler, int i)
{
	int y;
	int x;
	int f;

	f = 0;
	y = -1;
	x = -1;
	while (++y < filler->m_ymax)
	{
		while (++x < filler->m_xmax)
		{
			if (filler->hmap[y][x] == i)
			{
				if (!f)
					f = plague(filler, x, y, i);
				else
					plague(filler, x, y, i);
			}
		}
		x = -1;
	}
	if (f)
		plague_hmp(filler, i + 1);
	return (0);
}

/*
** CREATE A HEATMAP, AND ADJUST IT EVERY TURNS. IT ALSO GIVE
** ME THE INFO IN WICH DIRECTION I NEED TO GO TO RUSH MY ENEMY
** THE FASTEST AS POSSIBLE.
*/

void			create_heatmap(t_filler *filler)
{
	int x;
	int y;

	y = -1;
	if (!filler->hmap)
		malloc_hm(filler);
	x = -1;
	while (++y < filler->m_ymax)
	{
		while (++x < filler->m_xmax)
			what_todo(filler, y, x);
		x = -1;
	}
	plague_hmp(filler, ENEMY);
	last_check(filler);
}
