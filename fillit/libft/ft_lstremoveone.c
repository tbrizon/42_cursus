/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremoveone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:57:43 by tbrizon           #+#    #+#             */
/*   Updated: 2019/06/03 15:58:01 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstremoveone(t_list *previous, t_list **to_del)
{
	previous->next = (*to_del)->next;
	free((*to_del)->content);
	(*to_del)->content = NULL;
	free(*to_del);
	*to_del = NULL;
}
