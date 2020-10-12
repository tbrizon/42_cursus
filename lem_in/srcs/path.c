/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <jjaegle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:01:05 by jjaegle           #+#    #+#             */
/*   Updated: 2019/10/09 13:35:50 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**change_pred permet de changer les predecesseurs du chemin trouver par le
**BFS, le predecesseur n'est changer que si un chemin n'as pas ete remonter
*/

void			break_link(t_lemin *lem, int son, size_t dad)
{
	t_list	*room;
	t_list	*prev;

	room = lem->graph[son];
	if (room && room->content_size == dad)
		lem->graph[son] = room->next;
	else
	{
		while (room && room->content_size != dad)
		{
			prev = room;
			room = room->next;
		}
		if (room)
			prev->next = room->next;
	}
	if (room)
		room->next = NULL;
}

static void		change_pred(t_lemin *lem)
{
	t_fifo	*dad;
	size_t	son;

	dad = lem->tab[lem->end[ID]]->parent;
	son = lem->end[ID];
	while (dad)
	{
		if (PREDNB(dad->room) != son || (!son && !ID_USERNB(son)))
			PREDNB(son) = dad->room;
		else
		{
			break_link(lem, son, dad->room);
			break_link(lem, dad->room, son);
		}
		son = dad->room;
		dad = dad->parent;
	}
}

/*
**extract_dad recupere le papa de end pour un chemin donne
*/

static int		extract_dad(t_list2 *path, t_lemin *lem)
{
	while (path->next->room != lem->end[ID])
		path = path->next;
	return (path->room);
}

static t_path	*create_path(t_lemin *lem, t_list2 *other_paths, int name)
{
	t_path		*path;
	t_list2		*room;
	int			dad;

	path = malloc_in_gc(sizeof(t_path), lem);
	dad = extract_dad(other_paths, lem);
	room = extract_path(dad, lem, name);
	path->room = room;
	path->len = ft_sprintlen(path->room);
	return (path);
}

/*
**save_path prend un tableau de 2 boite a chemin et rempli la case concerne
**apres avoir modifier le tableau de predecesseur des rooms.
*/

void			save_path(t_path paths[2], int nb_path, t_lemin *lem)
{
	t_path	*path;
	t_path	*other;
	int		nbp;

	nbp = nb_path;
	path = &paths[nb_path % 2];
	path->id = nb_path;
	change_pred(lem);
	path->room = extract_path(PREDNB(lem->end[ID]), lem, nb_path);
	path->len = ft_sprintlen(path->room);
	other = &paths[!(nb_path % 2)];
	path->next = NULL;
	while (--nb_path)
	{
		ft_path_push(&path, create_path(lem, other->room, nb_path));
		other = other->next;
	}
	calc_round(path, lem->nb_ant, lem, nbp);
}
