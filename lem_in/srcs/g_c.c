/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_c.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <jjaegle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:59:47 by jjaegle           #+#    #+#             */
/*   Updated: 2019/10/08 14:48:20 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_usage(void)
{
	ft_printf("Usage : [rvplh]\n-r : print round\n-p : print paths\n");
	ft_printf("-l : print adjacency list\n-h : print hash-table\n");
	exit(EXIT_SUCCESS);
}

void		pars_arg(t_lemin *lem, char *av[], int ac)
{
	while (--ac)
	{
		if (!ft_strcmp(*(++av), "-r"))
			lem->round = 1;
		else if (!ft_strcmp(*av, "-p"))
			lem->paths = 1;
		else
			print_usage();
	}
}

void		*malloc_in_gc(size_t size, t_lemin *lem)
{
	t_list	*elem;
	void	*ret;

	if (!(elem = malloc(sizeof(t_list))))
		end_error(lem, "malloc error\n");
	if (!(ret = malloc(size)))
		end_error(lem, "malloc error\n");
	ft_bzero(ret, size);
	elem->content = ret;
	ft_lstadd(&lem->g_c, elem);
	return (ret);
}

void		add_in_gc(void *p, t_lemin *lem)
{
	t_list	*elem;

	if (!(elem = malloc(sizeof(t_list))))
		end_error(lem, "malloc error\n");
	elem->content = p;
	ft_lstadd(&lem->g_c, elem);
}

void		free_gc(t_list *lst)
{
	t_list	*clean;

	while (lst)
	{
		clean = lst;
		lst = lst->next;
		free(clean->content);
		free(clean);
	}
}
