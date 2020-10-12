/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <jjaegle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:25:57 by jjaegle           #+#    #+#             */
/*   Updated: 2019/10/28 09:44:17 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_fifo			*create_fifo_elem(int room, t_lemin *lem)
{
	t_fifo		*ret;

	ret = malloc_in_gc(sizeof(t_fifo), lem);
	ret->room = room;
	DISTANCENB(room) = 1;
	return (ret);
}

void			initialise(t_lemin *lem, int *end, t_fifo **fifo)
{
	t_room	**tab;
	int		i;

	tab = lem->tab;
	tab[lem->end[ID]]->parent = NULL;
	i = 0;
	*end = 0;
	while (i < lem->nb_room)
	{
		tab[i]->distance = ZER;
		tab[i]->ascend = ZER;
		i++;
	}
	*fifo = create_fifo_elem(lem->start[ID], lem);
}

void			test(t_lemin *lem, t_path *path)
{
	t_list2	*room;
	int		i;

	i = 1;
	ft_printf("\n Chemins trouvees :\n\n");
	while (path)
	{
		room = path->room;
		ft_printf("Chemin %d\n", i++);
		while (room)
		{
			ft_printf("%s", VALUE(room->room));
			if (room->room != lem->end[ID])
				ft_printf(" -> ");
			else
				ft_printf("\n");
			room = room->next;
		}
		path = path->next;
	}
}

static void		print_map(t_lemin *lem)
{
	ft_printf("%s", lem->ret);
	if (lem->ret[ft_strlen(lem->ret) - 1] != '\n')
		ft_printf("\n\n");
	else
		ft_printf("\n");
}

/*
**solve utilise un tableau de t_path, ce tableau de t_path va servir a
**sauvegarder les chemins trouveschaque case correspon au nombre de chemin
**la case 0 contient 1 chemin, la case 1 contient 2 chemin ...
**les chemins sont decouvert par l'algorithme de Moore, puis sauvegarder
**dans leurs structures. On traite le chemin en cas de collision.
**si tout est ok et qu'il y a encore un chemin a decouvrir on copie les
**chemins dans une nouvelle case de path et on recommence ...
*/

void			solve(t_lemin *lem)
{
	t_list		*end;
	int			i;
	t_path		paths[2];

	i = 1;
	end = NULL;
	ft_bzero(paths, sizeof(t_path) * 2);
	while (i <= lem->nb_pathmax)
	{
		basic_conductor(lem);
		if (DISTANCENB(lem->end[ID]))
		{
			save_path(paths, i, lem);
			if (!path_ok(i, paths) || paths[i % 2].len == 1)
				break ;
		}
		else
			break ;
		i++;
	}
	if (paths[i % 2].len != 1)
		i--;
	print_map(lem);
	print_sol(lem, &paths[i % 2]);
}
