/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <jjaegle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:14:13 by jjaegle           #+#    #+#             */
/*   Updated: 2019/10/28 09:45:23 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		end_error(t_lemin *lem, char *error)
{
	write(2, "ERROR\n", 6);
	free_gc(lem->g_c);
	if (lem->str)
		free(lem->str);
	write(2, error, ft_strlen(error));
	exit(EXIT_FAILURE);
}

int			check_nb_ant(t_lemin *lem, char *nb)
{
	long	num;

	num = ft_atol(nb);
	if (num <= 0 || num > 10000)
		return (1);
	lem->nb_ant = num;
	return (0);
}

char		*zap_com(char *str)
{
	char	*p;

	p = str;
	str = ft_strchr(p, '\n');
	if (str)
		*str = '\0';
	while (p[0] == '#' && ft_strcmp(p, "##start") && ft_strcmp(p, "##end"))
	{
		if (str)
		{
			*str = '\n';
			p = str + 1;
		}
		else
			p[0] = '\0';
		if ((str = ft_strchr(p, '\n')))
			*str = '\0';
	}
	if (str)
		*str = '\n';
	return (p);
}

void		add_room(char *p, t_lemin *lem)
{
	check_room(p, lem);
	lem->nb_room++;
}

int			ft_str_is(char *str, int (*f)(int))
{
	while (*str && *str != '\n')
	{
		if (!(*f)(*str))
			return (0);
		str++;
	}
	return (1);
}
