/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:30:08 by tbrizon           #+#    #+#             */
/*   Updated: 2019/05/02 11:57:39 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ajout l'element new en tete de liste
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}
