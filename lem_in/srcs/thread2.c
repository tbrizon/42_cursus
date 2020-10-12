/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <jjaegle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 10:38:12 by jjaegle           #+#    #+#             */
/*   Updated: 2019/10/28 15:44:36 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			dad_conductor(t_fifo *son, t_lemin *lem, int *end
	, t_fifo *prev)
{
	t_fifo		*fifo;

	ASCENDNB(son->room)++;
	if (ASCENDNB(son->room) > 2 || invalid_pred(son, lem))
		return ;
	fifo = NULL;
	fifo = create_fifo_elem(PREDNB(son->room), lem);
	fifo->parent = son;
	DISTANCENB(fifo->room) = DISTANCENB(son->room) - 1;
	if (!ASCENDNB(fifo->room)++)
		dad_conductor(fifo, lem, end, fifo);
	while (fifo && !(*end))
	{
		thread_id(fifo, lem, end, prev);
		fifo = fifo->next;
	}
}

static void		add_end_parent(t_lemin *lem, t_fifo *dad, int *end)
{
	*end = 1;
	lem->tab[lem->end[ID]]->parent = dad;
}

void			thread_id(t_fifo *dad, t_lemin *lem, int *end, t_fifo *prev)
{
	t_list		*sons;

	sons = lem->graph[dad->room];
	while (sons && !(*end))
	{
		if (ID_USER(sons) && ID_USER(sons) != ID_USERNB(dad->room)
			&& !ASCEND(sons))
			thread_id_to_id(sons, lem, end, dad);
		sons = sons->next;
	}
	sons = lem->graph[dad->room];
	while (sons && !(*end))
	{
		if (!ID_USER(sons) && (!DISTANCE(sons)
			|| DISTANCE(sons) > DISTANCENB(dad->room) + 1))
			thread_to_prev(sons, dad, lem, prev);
		if (ROOM(sons) == lem->end[ID])
			add_end_parent(lem, dad, end);
		sons = sons->next;
	}
}

static void		thread_fifo(t_fifo *dad, t_lemin *lem, int *end)
{
	t_list		*sons;

	sons = lem->graph[dad->room];
	while (sons && !(*end))
	{
		if (!ID_USER(sons) && !DISTANCE(sons))
			basic_thread(sons, dad, lem);
		if (ROOM(sons) == lem->end[ID])
			add_end_parent(lem, dad, end);
		sons = sons->next;
	}
	sons = lem->graph[dad->room];
	while (sons && !(*end))
	{
		if (ID_USER(sons) && !DISTANCE(sons) && !ASCEND(sons))
			thread_id_to_noid(sons, lem, end, dad);
		sons = sons->next;
	}
}

void			basic_conductor(t_lemin *lem)
{
	t_fifo		*fifo;
	int			end;

	initialise(lem, &end, &fifo);
	while (fifo && !end)
	{
		thread_fifo(fifo, lem, &end);
		fifo = fifo->next;
	}
}
