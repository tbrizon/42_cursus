/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaye <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:32:09 by yaye              #+#    #+#             */
/*   Updated: 2019/06/15 17:32:11 by yaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** AJOUTE LE MAILLON A LA FIN DE LA LISTE
*/

void	ft_lstaddbel(t_list **alst, t_list *new)
{
	t_list	*lpt;

	if (*alst == NULL)
		*alst = new;
	else
	{
		lpt = *alst;
		while (lpt->next)
			lpt = lpt->next;
		lpt->next = new;
	}
}

/*
** FREE ENTIEREMENT LA LISTE
*/

void	fillfree(t_list **lst)
{
	t_list	*lpt;

	lpt = *lst;
	while (lpt)
	{
		lpt = (*lst)->next;
		(*lst)->content = NULL;
		free((*lst)->content);
		free(*lst);
		*lst = lpt;
	}
}

/*
** REALLOC BOARD->STR SELON SA BOARD->SIZE
*/

void	resize(t_board *board, t_list *lst)
{
	int		i;

	if (board->str)
		free(board->str);
	if (!(board->str = (char *)malloc(sizeof(char)
		* (board->size * (board->size + 1) + 1))))
	{
		fillfree(&lst);
		exit(1);
	}
	i = 0;
	while (i < board->size * (board->size + 1))
	{
		if (i % (board->size + 1) == board->size)
			board->str[i] = '\n';
		else
			board->str[i] = '.';
		i = i + 1;
	}
	board->str[i] = 0;
}

/*
** PLACE LE TETRIMINOS ACTUEL A SA POSITION TETRIS->POS
*/

int		set_to(t_board *board, t_tris *tetris)
{
	int	i;
	int	r;
	int	x0;
	int	y0;

	i = 1;
	r = 0;
	x0 = tetris->bloc[0].x;
	y0 = tetris->bloc[0].y;
	tetris->bloc[0].x = tetris->pos % (board->size + 1);
	tetris->bloc[0].y = tetris->pos / (board->size + 1);
	while (i < 4)
	{
		tetris->bloc[i].x = tetris->bloc[0].x + tetris->bloc[i].x - x0;
		if (tetris->bloc[i].x < 0 || tetris->bloc[i].x >= board->size)
			r = -1;
		tetris->bloc[i].y = tetris->bloc[0].y + tetris->bloc[i].y - y0;
		if (tetris->bloc[i].y < 0 || tetris->bloc[i].y >= board->size)
			r = -1;
		i = i + 1;
	}
	return (r);
}
