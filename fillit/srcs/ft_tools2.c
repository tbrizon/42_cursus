/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaye <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:01:16 by yaye              #+#    #+#             */
/*   Updated: 2019/06/18 16:01:17 by yaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** MESURE LE POID (NOMBRE DE TETRIMINOS x 4) POUR CALCULER LE NOMBRE
** DE CASES RESTANTES A POSER
*/

int		weight(t_list *lst)
{
	int		weight;
	t_list	*lpt;
	t_tris	*tpt;

	weight = 0;
	lpt = lst;
	while (lpt)
	{
		weight = weight + 4;
		tpt = (t_tris *)lpt->content;
		lpt = lpt->next;
	}
	return (weight);
}

/*
** CHANSON DE RADIOHEAD, PERMET EN FONCTION D'UNE POSITION D'EMETTRE UN CHAMP
** D'EMPLACEMENT POSSIBLE. IL CONTAMINE LES CASES VIDES '.' ADJACENTES
*/

int		creep(char *str, int size, int i)
{
	int		x;

	x = 1;
	str[i] = TUMOR;
	if (str[i + size + 1] == '.')
		x = x + creep(str, size, i + size + 1);
	if (str[i - size - 1] == '.')
		x = x + creep(str, size, i - size - 1);
	if (str[i + 1] == '.')
		x = x + creep(str, size, i + 1);
	if (str[i - 1] == '.')
		x = x + creep(str, size, i - 1);
	return (x);
}

/*
** MESURE LE POID POSABLE SUR LE TABLEAU
*/

int		scan(char *str, int size)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if ((y = creep(str, size, i)) >= 4)
				x = x + y;
		}
		i = i + 1;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == TUMOR)
			str[i] = '.';
		i = i + 1;
	}
	return (x);
}
