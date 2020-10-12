/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <tbrizon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 12:03:31 by tbrizon           #+#    #+#             */
/*   Updated: 2019/09/11 11:03:41 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		wich_dir(t_filler *filler)
{
	if (filler->m_dir[0] && filler->e_dir[3])
		return (1);
	if (filler->m_dir[0] && filler->e_dir[1])
		return (1);
	if (filler->m_dir[1] && filler->e_dir[2])
		return (1);
	if (filler->m_dir[1] && filler->e_dir[0])
		return (1);
	return (0);
}

void	direction(t_filler *filler, int *direction, int y, int x)
{
	if (direction[0] + direction[1] + direction[2] + direction[3] > 1)
		re_init(direction);
	if (x < filler->m_xmax / 2 && y < filler->m_ymax / 2)
		direction[0] = 1;
	if (x > filler->m_xmax / 2 && y < filler->m_ymax / 2)
		direction[1] = 1;
	if (x < filler->m_xmax / 2 && y > filler->m_ymax / 2)
		direction[2] = 1;
	if (x > filler->m_xmax / 2 && y > filler->m_ymax / 2)
		direction[3] = 1;
}

void	what_todo(t_filler *filler, int y, int x)
{
	if (filler->map[y][x] == filler->letter_enemy + 32
	|| filler->map[y][x] == filler->letter_enemy)
	{
		filler->hmap[y][x] = ENEMY;
		direction(filler, filler->e_dir, y, x);
	}
	else if (filler->map[y][x] == filler->letter_me
	|| filler->map[y][x] == filler->letter_me + 32)
	{
		filler->hmap[y][x] = ME;
		direction(filler, filler->m_dir, y, x);
	}
	else
		filler->hmap[y][x] = 0;
}

void	free_piece(t_filler *filler)
{
	int y;

	y = 0;
	while (y < filler->p_ymax)
		ft_strdel(&filler->piece[y++]);
	free(filler->piece);
	filler->piece = NULL;
}

void	free_filler(t_filler *filler)
{
	int y;

	y = 0;
	while (y < filler->m_ymax)
	{
		free(filler->hmap[y]);
		ft_strdel(&filler->map[y++]);
	}
	free(filler->hmap);
	free(filler->map);
	filler->hmap = NULL;
	filler->map = NULL;
	if (filler->piece)
		free_piece(filler);
	filler->piece = NULL;
}
