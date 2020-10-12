/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:59:07 by tbrizon           #+#    #+#             */
/*   Updated: 2019/06/03 15:59:09 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list	*list;

	if (alst && *alst && new)
	{
		list = *alst;
		while (list->next)
			list = list->next;
		list->next = new;
	}
}
