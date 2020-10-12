/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:59:58 by tbrizon           #+#    #+#             */
/*   Updated: 2019/06/06 09:59:59 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	boot(t_board *board, t_tris *tetris)
{
	board->str = NULL;
	board->size = 2;
	board->lsiz = 0;
	board->n = 0;
	tetris->letter = 'A' - 1;
	tetris->pos = 0;
}

/*
** VERIFIE QUE LA FORME DU TETRIMINOS
*/

int		check_shape(char *buf)
{
	int		weight;
	int		i;

	weight = 0;
	i = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if (buf[i + 1] == '#' && (i + 1) < 20)
				weight = weight + 1;
			if (buf[i - 1] == '#' && (i - 1) >= 0)
				weight = weight + 1;
			if (buf[i + 5] == '#' && (i + 5) < 20)
				weight = weight + 1;
			if (buf[i - 5] == '#' && (i - 5) >= 0)
				weight = weight + 1;
		}
		i = i + 1;
	}
	return ((weight == 6 || weight == 8) ? 1 : 0);
}

/*
** STOCKE LES COORDONNEES DES PIECES DANS UNE LISTE DE TETRIS
** LA LONGUEUR DE LA LISTE EST MESUREE
*/

void	parsing(t_board *board, t_list **lst, t_tris *tetris, char *buf)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			tetris->bloc[n].x = i % 5;
			tetris->bloc[n].y = i / 5;
			n = n + 1;
		}
		i = i + 1;
	}
	board->lsiz = board->lsiz + 1;
	tetris->letter = tetris->letter + 1;
	ft_lstaddbel(lst, ft_lstnew(tetris, sizeof(t_tris)));
}

/*
** VERIFIE LE FORMAT DE L'ENTREE
*/

int		check(int ret, char *str)
{
	int		bloc;
	int		i;

	bloc = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (str[i] != '.' && str[i] != '#')
				return (1);
			if (str[i] == '#' && (bloc = bloc + 1) > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i = i + 1;
	}
	if (str[20] != '\n' && ret == 21)
		return (4);
	if (!check_shape(str))
		return (5);
	return (0);
}

/*
** FONCTION PRINCIPALE, LIT LE PATERN ET LE RESOUT
*/

void	fillit(int fd, t_list *lst)
{
	int			cmpt;
	char		buff[21];
	t_tris		tetris;
	t_board		board;
	int			ret;

	cmpt = -1;
	boot(&board, &tetris);
	while ((ret = read(fd, buff, 21)) >= 20)
	{
		if (ret == 20)
			cmpt++;
		if (check(ret, buff))
		{
			ft_putendl("error");
			return (fillfree(&lst));
		}
		else
			parsing(&board, &lst, &tetris, buff);
	}
	(!ret && !cmpt) ? norminette(cmpt, &board, lst)
	: ft_putendl("error");
	return (fillfree(&lst));
}
