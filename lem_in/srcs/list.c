/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <jjaegle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:41:09 by jjaegle           #+#    #+#             */
/*   Updated: 2019/10/08 11:30:11 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_sprint_add(t_list2 **ad, t_list2 *new)
{
	new->next = *ad;
	*ad = new;
}

void		ft_path_push(t_path **ad, t_path *new)
{
	t_path		*path;

	if (!*ad)
		*ad = new;
	else
	{
		path = *ad;
		while (path->next)
			path = path->next;
		path->next = new;
	}
}

void		ft_fifo_push(t_fifo **ad, t_fifo *new, t_lemin *lem)
{
	t_fifo		*p;

	if (DISTANCENB(new->room) != DISTANCENB((*ad)->room) + 1)
		DISTANCENB(new->room) = DISTANCENB((*ad)->room) + 1;
	if (!*ad)
		*ad = new;
	else
	{
		p = *ad;
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

int			ft_sprintlen(t_list2 *elem)
{
	int		i;

	i = 0;
	while (elem)
	{
		elem = elem->next;
		i++;
	}
	return (i);
}
