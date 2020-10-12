/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:58:35 by tbrizon           #+#    #+#             */
/*   Updated: 2019/06/03 15:58:37 by tbrizon          ###   ########.fr       */
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
