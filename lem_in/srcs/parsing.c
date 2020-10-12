/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <jjaegle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:15:27 by jjaegle           #+#    #+#             */
/*   Updated: 2019/10/25 14:01:16 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**create_room cree une structure room a partir de sa representation ecrite
*/

t_room			*create_room(char *str, t_lemin *lem)
{
	t_room	*new;
	char	*p;

	p = str;
	new = (t_room*)malloc_in_gc(sizeof(t_room), lem);
	p = ft_strchr(str, ' ');
	*p = '\0';
	new->value = ft_strdup(str);
	add_in_gc(new->value, lem);
	*p = ' ';
	str = p + 1;
	new->x = ft_atoi(str);
	new->y = ft_atoi(ft_strchr(str, ' '));
	return (new);
}

static void		parse_tube(char *str, t_list *hash[], t_lemin *lem)
{
	char		*p;

	p = str;
	while ((str = ft_strchr(p, '\n')) || p)
	{
		if (str)
			*str = '\0';
		if (!ft_strcmp(p, "##start") && !ft_strcmp(p, "##end") && !(*p = '\0'))
			return ;
		else if (p[0] != '#' && ft_strcmp(p, "##start")
				&& ft_strcmp(p, "##end"))
		{
			if (!is_tube(p) || !add_tube(p, hash, lem))
			{
				*p = '\0';
				return ;
			}
		}
		if (str)
			*str = '\n';
		p = (str) ? str + 1 : NULL;
	}
}

/*
**Le parsing est composer de plusieurs etapes :
**1) Creation d'une table de hachage
**2) Creation du graphe
*/

void			parsing(t_lemin *lemin)
{
	t_list	*hash[lemin->nb_room];
	char	*p;

	ft_bzero(hash, sizeof(t_list*) * lemin->nb_room);
	lemin->tab = (t_room**)malloc_in_gc(sizeof(t_room*) * lemin->nb_room
		, lemin);
	p = fill_hash(hash, lemin->ret, lemin->nb_room, lemin);
	lemin->graph = (t_list**)malloc_in_gc(sizeof(t_list*) * lemin->nb_room
		, lemin);
	parse_tube(p, hash, lemin);
	lemin->start[DEGREE] = ft_lstlen(lemin->graph[lemin->start[ID]]);
	lemin->end[DEGREE] = ft_lstlen(lemin->graph[lemin->end[ID]]);
	lemin->nb_pathmax = (lemin->start[DEGREE] < lemin->end[DEGREE])
	? lemin->start[DEGREE] : lemin->end[DEGREE];
	lemin->nb_pathmax = (lemin->nb_ant < lemin->nb_pathmax)
	? lemin->nb_ant : lemin->nb_pathmax;
}
