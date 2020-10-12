/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soluce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <jjaegle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 11:39:15 by jjaegle           #+#    #+#             */
/*   Updated: 2019/10/09 12:19:14 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list2			*create_elem(int room, t_lemin *lem)
{
	t_list2	*ret;

	ret = malloc_in_gc(sizeof(t_list2), lem);
	ret->room = room;
	ret->next = NULL;
	return (ret);
}

int				calc_ant_by_path(t_path *path, int rounds)
{
	int		sum;

	sum = 0;
	while (path)
	{
		path->nb_ant = rounds + 1 - path->len;
		if (path->nb_ant <= 0)
			return (1);
		sum += path->nb_ant;
		path = path->next;
	}
	return (0);
}

void			print_sol(t_lemin *lem, t_path *path)
{
	int		ant;
	int		round;

	if (path->len == 1)
	{
		print_all_in_one(lem, path);
		return ;
	}
	round = path->rounds;
	adjust_path(path, lem->nb_ant);
	ant = 1;
	while (round--)
	{
		if (lem->round)
			ft_printf("\nRound %d : \n", path->rounds - round);
		print_round(path, lem, &ant);
		ft_printf("\n");
	}
	if (lem->round)
		ft_printf("\nNombre total de round = %d\n", path->rounds);
	if (lem->paths)
		test(lem, path);
}

void			calc_round(t_path *path, int nb_ant, t_lemin *lem, int nb_path)
{
	t_path	*first;

	first = path;
	first->rounds = 0;
	lem->sum_path = 0;
	while (path)
	{
		lem->sum_path += path->len;
		path = path->next;
	}
	first->rounds = (lem->sum_path + nb_ant - 1) / nb_path;
}
