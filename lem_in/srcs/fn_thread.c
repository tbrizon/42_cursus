/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <jjaegle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:06:38 by jjaegle           #+#    #+#             */
/*   Updated: 2019/10/09 13:33:35 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	thread_to_prev(t_list *sons, t_fifo *dad, t_lemin *lem, t_fifo *fifo)
{
	t_fifo	*son;

	son = create_fifo_elem(ROOM(sons), lem);
	son->parent = dad;
	DISTANCENB(son->room) = DISTANCENB(dad->room) + 1;
	ft_fifo_push(&fifo, son, lem);
}

void	basic_thread(t_list *sons, t_fifo *dad, t_lemin *lem)
{
	t_fifo	*son;

	son = create_fifo_elem(ROOM(sons), lem);
	son->parent = dad;
	DISTANCENB(son->room) = DISTANCENB(dad->room) + 1;
	ft_fifo_push(&dad, son, lem);
}

void	thread_id_to_noid(t_list *sons, t_lemin *lem, int *end, t_fifo *dad)
{
	t_fifo	*son;

	son = create_fifo_elem(ROOM(sons), lem);
	son->parent = dad;
	DISTANCENB(son->room) = DISTANCENB(dad->room) + 1;
	dad_conductor(son, lem, end, dad);
}

void	thread_id_to_id(t_list *sons, t_lemin *lem, int *end, t_fifo *dad)
{
	t_fifo	*son;

	son = create_fifo_elem(ROOM(sons), lem);
	son->parent = dad;
	DISTANCENB(son->room) = DISTANCENB(dad->room);
	dad_conductor(son, lem, end, dad);
}

t_list2	*extract_path(size_t last, t_lemin *lem, int name)
{
	t_list2	*elem;

	elem = create_elem(lem->end[ID], lem);
	while (last != lem->start[ID])
	{
		ft_sprint_add(&elem, create_elem(last, lem));
		ID_USERNB(last) = name;
		last = PREDNB(last);
	}
	return (elem);
}
