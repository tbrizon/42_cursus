/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:07:49 by tbrizon           #+#    #+#             */
/*   Updated: 2019/06/06 15:07:50 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
**		DESCRIPTION
**	Inverse une liste
*/

void	ft_lstrev(t_list **alst)
{
	t_list *cur;
	t_list *next;
	t_list *prev;

	prev = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}
