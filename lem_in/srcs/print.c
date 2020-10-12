/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <jjaegle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:50:24 by jjaegle           #+#    #+#             */
/*   Updated: 2019/10/09 12:15:47 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_ant(t_path *path, t_list2 **room)
{
	int		i;
	int		ret;

	ret = 0;
	i = -path->nb_ant + 1;
	while (--i)
		if (*room)
			*room = (*room)->next;
	if (*room)
		ret = (*room)->ant;
	if (*room)
		*room = (*room)->next;
	return (ret);
}

void		print_all_in_one(t_lemin *lem, t_path *path)
{
	int		i;

	i = 0;
	if (lem->round)
		ft_printf("\nRound 1 : \n");
	while (++i <= lem->nb_ant)
		ft_printf("L%d-%s%c", i, VALUE(lem->end[ID])
			, (i < lem->nb_ant) ? ' ' : '\n');
	if (lem->round)
		ft_printf("\nNombre total de round = 1\n");
	if (lem->paths)
		test(lem, path);
}

static void	print_path(t_list2 *room, t_lemin *lem, int *numant, t_path *path)
{
	int		ant;
	int		tmp;

	ant = (path->nb_ant > 0) ? *numant : get_ant(path, &room);
	tmp = 0;
	while (room && ant)
	{
		tmp = room->ant;
		room->ant = ant;
		ant = tmp;
		ft_printf("L%d-%s", room->ant, VALUE(room->room));
		room = room->next;
		if (room && ant)
			ft_printf(" ");
	}
	if (path->nb_ant-- > 0)
		(*numant)++;
}

void		print_round(t_path *path, t_lemin *lem, int *ant)
{
	while (path)
	{
		print_path(path->room, lem, ant, path);
		if ((path = path->next))
			ft_printf(" ");
	}
}

void		adjust_path(t_path *path, int nbant)
{
	int		i;

	i = 0;
	while (path)
	{
		i += path->nb_ant;
		if (i > nbant)
		{
			path->nb_ant -= i - nbant;
			break ;
		}
		path = path->next;
	}
}
