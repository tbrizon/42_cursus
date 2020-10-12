/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integrer_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:43:31 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/15 11:43:32 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	Trie un tableau d'entier par ordre croissant.
*/

void	ft_sort_integrer_tab(int *tab, int size)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
