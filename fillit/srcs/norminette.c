/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminette.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:58:11 by tbrizon           #+#    #+#             */
/*   Updated: 2019/06/18 15:58:12 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** PAS DE PLACES LES FREROTS
*/

void	norminette(int cmpt, t_board *board, t_list *lst)
{
	cmpt = 2;
	while (cmpt * cmpt < board->lsiz * 4)
		cmpt = cmpt + 1;
	board->size = cmpt;
	resize(board, lst);
	solve(board, lst, lst);
}
