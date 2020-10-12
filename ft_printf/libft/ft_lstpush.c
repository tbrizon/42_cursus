/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:02:06 by jjaegle           #+#    #+#             */
/*   Updated: 2019/04/08 14:07:37 by jjaegle          ###   ########.fr       */
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
