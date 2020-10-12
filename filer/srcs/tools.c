/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <tbrizon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:35:35 by tbrizon           #+#    #+#             */
/*   Updated: 2019/09/11 11:03:31 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init(t_filler *filler)
{
	ft_bzero(filler, sizeof(*filler));
	filler->best_pos[0] = 0;
	filler->best_pos[1] = 0;
	filler->letter_me = 'X';
	filler->letter_enemy = 'X';
}

void	re_initcount(t_filler *filler)
{
	filler->hmap_count = 0;
	filler->best_pos[1] = 0;
	filler->best_pos[0] = 0;
}

void	re_init(int *direction)
{
	int i;

	i = -1;
	while (++i <= 4)
		direction[i] = 0;
}

void	init_tok(t_token *t)
{
	t->r = 0;
	t->p_x = -1;
	t->p_y = -1;
	t->f = 0;
}

void	malloc_hm(t_filler *filler)
{
	int x;

	x = 0;
	filler->hmap = (int **)malloc(sizeof(int *) * filler->m_ymax);
	while (x < filler->m_ymax)
		filler->hmap[x++] = (int *)malloc(sizeof(int) * filler->m_xmax);
}
