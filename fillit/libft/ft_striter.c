/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:35:07 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/08 11:35:08 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	Applique la fonction f a chaque caractere de la chaine de caracteres.
**	Chaque caractere est passe par adresse a la fonction f afin de pouvoir
**	etre modifie si necessaire.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (!s || !f)
		return ;
	while (*s && f)
		f(s++);
}
