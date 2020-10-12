/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <tbrizon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:18:45 by tbrizon           #+#    #+#             */
/*   Updated: 2019/09/11 11:03:23 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			new_best(t_filler *filler, int x, int y, int count)
{
	filler->hmap_count = count;
	filler->best_pos[0] = x;
	filler->best_pos[1] = y;
}

/*
** TAKE THE BEST PLACE BY ADDITIONNING THE HEATMAP X Y WEIGHT
** ALSO THE DIRECTION WILL BE AJUSTED WITH THE FOUNCTION WICH_DIR
*/

static void		count_hmp(t_filler *filler, int x, int y)
{
	int count;
	int p_y;
	int p_x;

	p_x = -1;
	p_y = -1;
	count = 0;
	while (++p_y < filler->p_ymax)
	{
		while (++p_x < filler->p_xmax)
		{
			if (filler->piece[p_y][p_x] == '*'
			&& filler->hmap[p_y + y][p_x + x] > 0)
				count += filler->hmap[p_y + y][p_x + x];
		}
		p_x = -1;
	}
	if (!filler->hmap_count)
		new_best(filler, x, y, count);
	else if (count <= filler->hmap_count
	&& (filler->returnvalue = wich_dir(filler)))
		new_best(filler, x, y, count);
	else if (count < filler->hmap_count
	&& !(filler->returnvalue = wich_dir(filler)))
		new_best(filler, x, y, count);
}

/*
** CHECK IF THE TOKEN'S POSITION IS CORRECT
*/

int				check_piece(t_filler *f, int x, int y, char c)
{
	t_token t;

	init_tok(&t);
	while (++t.p_y < f->p_ymax)
	{
		while (++t.p_x < f->p_xmax)
		{
			if (f->piece[t.p_y][t.p_x] == '*')
			{
				if (t.p_x + x >= 0 && t.p_y + y >= 0 && t.p_x + x < f->m_xmax
				&& t.p_y + y < f->m_ymax
				&& f->hmap[y + t.p_y][x + t.p_x] != ENEMY)
				{
					if (f->map[y + t.p_y][x + t.p_x] == c
					|| f->map[y + t.p_y][x + t.p_x] == c + 32)
						t.f++;
				}
				else
					t.r = 1;
			}
		}
		t.p_x = -1;
	}
	return ((!t.r && t.f == 1) ? 0 : 1);
}

/*
** TRY TO PLACE THE TOKEN IN THE MAP, REGARDING IF THE TOKEN'S POSITION
** IS CORRECT (CHECK_PIECE'S FOUNCTION'S) AND COUNTING THE TOKEN'S WEIGHT
** WITH THE HEATMAP (COUNT_HMP'S FOUNCTION) IN ORDER TO FIND THE BEST
** TOKEN'S POSITION.
*/

void			place_piece(t_filler *filler)
{
	int start_x;
	int start_y;

	start_x = 0;
	start_y = 0;
	start_x -= filler->p_xmax;
	start_y -= filler->p_ymax;
	while (++start_y < filler->m_ymax)
	{
		while (++start_x < filler->m_xmax)
		{
			if (!check_piece(filler, start_x, start_y, filler->letter_me))
				count_hmp(filler, start_x, start_y);
		}
		start_x = 0 - filler->p_xmax;
	}
}

/*
** LAUNCH THE SOLVERS FOUNCTIONS AND WRITE ON THE STANDARD EXIT
** THE POSITION "Y, X\n" FOUND BY THE ALGORITHME
*/

void			solver(t_filler *filler)
{
	place_piece(filler);
	ft_putnbr(filler->best_pos[1]);
	ft_putchar(' ');
	ft_putnbr(filler->best_pos[0]);
	ft_putchar('\n');
	re_initcount(filler);
}
