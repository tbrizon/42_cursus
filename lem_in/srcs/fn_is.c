/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <jjaegle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:30:18 by jjaegle           #+#    #+#             */
/*   Updated: 2019/10/09 13:30:33 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**retourne 1 si la ligne lu est un tube 0 sinon + gere les erreures
**de syntaxe
*/

int			is_tube(char *str)
{
	char	*p;

	p = str;
	str = ft_strchr(p, '\n');
	if (str)
		*str = '\0';
	if (!ft_isalnum(*p))
		return (0);
	while (ft_isalnum(*p) || *p == '_')
		p++;
	if (*p == '-')
		p++;
	else
		return (0);
	if (!*p)
		return (0);
	while (ft_isalnum(*p) || *p == '_')
		p++;
	if (str)
		*str = '\n';
	return ((!*p) ? 1 : 0);
}

/*
**has_collistion verifie qu'un chemin represente par une liste possede
**une collision en verifiant que les sommets du chemin ont bien comme
**id_user l'id du chemin, si id_user > id_chemin => Collision.
*/

int			has_collistion(int id_path, t_list *path, t_room *tab[])
{
	while (path->next)
	{
		if (tab[ROOM(path)]->id_user != id_path)
			return (tab[ROOM(path)]->id_user - id_path);
		path = path->next;
	}
	return (0);
}

int			is_pst(size_t id, t_list *lst)
{
	while (lst)
	{
		if (lst->content_size == id)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int			path_ok(int i, t_path paths[2])
{
	if (i > 1 && paths[i % 2].rounds > paths[!(i % 2)].rounds)
		return (0);
	if (calc_ant_by_path(&paths[i % 2], paths[i % 2].rounds))
		return (0);
	return (1);
}
