/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:41:27 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/08 11:41:28 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	Applique la fonction f a chaque caractere de la chaine de caracteres en
**	precisant son index en premier argument.
**	Chaque caractere est passe par adresse a la fonction f afin de pouvoir
**	etre modifie si necessaire.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (*s)
		f(i++, s++);
}
