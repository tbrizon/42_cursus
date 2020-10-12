/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <jjaegle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:48:03 by jjaegle           #+#    #+#             */
/*   Updated: 2019/10/25 13:17:16 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	create_tube(int id1, int id2, t_lemin *lem)
{
	t_list	*elem1;
	t_list	*elem2;

	if (!is_pst(id2, lem->graph[id1]))
	{
		elem1 = malloc_in_gc(sizeof(t_list), lem);
		ft_bzero(elem1, sizeof(t_list));
		elem2 = malloc_in_gc(sizeof(t_list), lem);
		ft_bzero(elem2, sizeof(t_list));
		elem1->content_size = id1;
		elem2->content_size = id2;
		ft_lstpush(&lem->graph[id1], elem2);
		ft_lstpush(&lem->graph[id2], elem1);
	}
}

int			invalid_pred(t_fifo *son, t_lemin *lem)
{
	t_list		*neighb;

	if (PREDNB(son->room) == lem->start[ID])
		return (1);
	neighb = lem->graph[son->room];
	while (neighb)
	{
		if (ROOM(neighb) == PREDNB(son->room))
			return (0);
		neighb = neighb->next;
	}
	return (1);
}

int			add_tube(char *str, t_list *hash[], t_lemin *lem)
{
	char		*p;
	int			id1;
	int			id2;

	p = ft_strchr(str, '-');
	*p = '\0';
	if ((id1 = get_id(hash, str, lem->nb_room)) == -1
		|| (id2 = get_id(hash, p + 1, lem->nb_room)) == -1)
		return (0);
	create_tube(id1, id2, lem);
	*p = '-';
	return (1);
}
