/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaye <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:32:58 by yaye              #+#    #+#             */
/*   Updated: 2019/06/18 15:49:31 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		first(t_board *board)
{
	int		i;

	i = 0;
	while (board->str[i])
	{
		if (board->str[i] == '.')
			return (i);
		i = i + 1;
	}
	return (0);
}

int		valid(t_board *board, t_tris *tetris)
{
	if (tetris->bloc[3].y - tetris->bloc[0].y \
		>= board->size - tetris->pos / (board->size + 1))
		return (0);
	if (tetris->pos >= board->size * (board->size + 1) - 4)
		return (0);
	return (1);
}

int		tcheck_nput(t_board *brd, t_list *lst, t_list *lcur)
{
	t_tris	*t;
	int		i;

	t = (t_tris *)lcur->content;
	if ((i = set_to(brd, t)) == -1)
		return (0);
	while (i < 4)
	{
		if (brd->str[t->bloc[i].x + t->bloc[i].y * (brd->size + 1)] != '.')
			return (0);
		i = i + 1;
	}
	if (weight(lcur) > scan(brd->str, brd->size))
		return (0);
	while ((i = i - 1) >= 0)
		brd->str[t->bloc[i].x + t->bloc[i].y * (brd->size + 1)] = t->letter;
	brd->n = brd->n + 1;
	if (brd->n == brd->lsiz)
	{
		ft_putstr(brd->str);
		fillfree(&lst);
		free(brd->str);
		exit(0);
	}
	return (1);
}

void	remove_tetris(t_board *board, t_tris *tetris)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		board->str[tetris->bloc[i].x \
			+ tetris->bloc[i].y * (board->size + 1)] = '.';
		i = i + 1;
	}
	board->n = board->n - 1;
}

void	solve(t_board *board, t_list *lst, t_list *lcur)
{
	t_tris *tbeg;
	t_tris *tcur;

	tbeg = (t_tris *)lst->content;
	tcur = (t_tris *)lcur->content;
	tcur->pos = first(board);
	while (valid(board, tcur))
	{
		if (tcheck_nput(board, lst, lcur))
		{
			solve(board, lst, lcur->next);
			remove_tetris(board, tcur);
		}
		tcur->pos = tcur->pos + 1;
	}
	if (tcur->letter == 'A')
	{
		board->size = board->size + 1;
		board->n = 0;
		resize(board, lst);
		solve(board, lst, lst);
	}
}
