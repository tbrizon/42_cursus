/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <jjaegle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:32:49 by jjaegle           #+#    #+#             */
/*   Updated: 2019/10/09 13:34:03 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			hash_function(char *str, int nb)
{
	int		i;

	i = 0;
	while (*str && *str != ' ')
		i += *str++;
	return (i % nb);
}

/*
**get_id retuourne l'id de la valeur passer en parametre si elle existe,
**-1 sinon;
*/

int			get_id(t_list *hash[], char *value, int nb)
{
	int		key;
	t_list	*lst;
	t_room	*room;

	key = hash_function(value, nb);
	if ((lst = hash[key]))
	{
		if (!lst->next && !ft_strcmp(value, ((t_room*)lst->content)->value))
			return (((t_room*)lst->content)->id);
		while (lst)
		{
			room = (t_room*)lst->content;
			if (!ft_strcmp(value, room->value))
				return (room->id);
			lst = lst->next;
		}
	}
	return (-1);
}

static void	try_flag(size_t start[], size_t end[], int id)
{
	if (start[FLAG] || end[FLAG])
	{
		if (start[FLAG] && !(start[FLAG] = 0))
			start[ID] = id;
		if (end[FLAG] && !(end[FLAG] = 0))
			end[ID] = id;
	}
}

static void	put_hash(t_list *hash[], int key, t_room *room, t_lemin *lem)
{
	static int	id = 0;
	t_room		*tmp;
	t_list		*elem;
	t_list		*lst;

	elem = ft_lstnew(NULL, 0);
	add_in_gc(elem, lem);
	elem->content = room;
	room->id = id;
	lem->tab[id] = room;
	if (!(lst = hash[key]))
		ft_lstadd(&hash[key], elem);
	else
	{
		while (lst)
		{
			tmp = (t_room*)lst->content;
			if (!ft_strcmp(room->value, tmp->value))
				end_error(lem, "two identical rooms\n");
			lst = lst->next;
		}
		ft_lstpush(&hash[key], elem);
	}
	try_flag(lem->start, lem->end, id++);
}

/*
**l'objectif de fill hash est de creer les rooms et de detecter les
**salles qui auraient deux fois le meme nom.
*/

char		*fill_hash(t_list *hash[], char *str, int nb, t_lemin *lemin)
{
	char	*p;

	p = zap_com(str);
	p = ft_strchr(p, '\n') + 1;
	while ((str = ft_strchr(p, '\n')))
	{
		*str = '\0';
		if (ft_strchr(p, '-'))
			break ;
		if (!ft_strcmp(p, "##start"))
			lemin->start[FLAG]++;
		else if (!ft_strcmp(p, "##end"))
			lemin->end[FLAG]++;
		if (!ft_strchr(p, '-') && !ft_strchr(p, '#'))
			put_hash(hash, hash_function(p, nb), create_room(p, lemin), lemin);
		*str = '\n';
		p = str + 1;
	}
	if (str)
		*str = '\n';
	return (p);
}
