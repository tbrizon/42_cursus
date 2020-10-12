/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:30:45 by jjaegle           #+#    #+#             */
/*   Updated: 2019/04/12 16:12:41 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelfirst(t_list **alst)
{
	t_list	*list;

	list = (*alst)->next;
	free((*alst)->content);
	(*alst)->content = NULL;
	free(*alst);
	*alst = list;
}
