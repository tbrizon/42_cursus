/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <jjaegle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:40:01 by jjaegle           #+#    #+#             */
/*   Updated: 2019/10/09 12:17:55 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		create_ant(t_list *room, int numant, t_lemin *lem)
{
	int		*ant;

	ant = malloc_in_gc(sizeof(int), lem);
	*ant = numant;
	room->content = ant;
}

void		print_adj(t_lemin *lem)
{
	t_list	*lst;
	int		i;

	i = -1;
	ft_printf("\n");
	while (++i < lem->nb_room)
	{
		ft_printf("%s =", VALUE(i));
		lst = lem->graph[i];
		while (lst)
		{
			ft_printf(" %s", VALUE(lst->content_size));
			lst = lst->next;
			if (lst)
				ft_printf(" -");
		}
		ft_printf("\n");
	}
}
