/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <jjaegle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:29:33 by jjaegle           #+#    #+#             */
/*   Updated: 2019/10/25 13:10:36 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**Check_room est appeler par get_nbroom afin de verifier que la room
**est au bon format, sinon => "Error"
*/

void		check_room(char *str, t_lemin *lem)
{
	if (str[0] == 'L')
		end_error(lem, "Character unauthorized\n");
	while (ft_isalnum(*str) || *str == '_')
		str++;
	if (*str == ' ')
		str++;
	else
		end_error(lem, "Wronx room syntax\n");
	while (ft_isdigit(*str))
		str++;
	if (*str == ' ')
		str++;
	else
		end_error(lem, "Wronx room syntax\n");
	while (ft_isdigit(*str))
		str++;
	if (*str)
		end_error(lem, "Wronx room syntax\n");
}

/*
**verifie qu'il y ait bien une room derriere les commandes end et start
**sinon => Error
*/

static void	check_com(char *str, size_t *tab, t_lemin *lem)
{
	char	*p;

	if (++tab[0] != 1)
		end_error(lem, "Identical commands");
	p = zap_com(str);
	if (p != str && (!ft_strncmp(p, "##start", 7)
		|| !ft_strncmp(p, "##end", 5)))
		end_error(lem, "Identical commands");
	str = ft_strchr(p, '\n');
	if (str)
		*str = '\0';
	check_room(p, lem);
	if (str)
		*str = '\n';
}

/*
**first pars a 2 utilites:
**1)Met a jour les variables nb_ant et nb_room
**2)Analyse syntaxique et gestion d'erreur des differentes lignes
*/

static void	first_pars(char *str, t_lemin *lem)
{
	char	*p;

	p = zap_com(str);
	if (!ft_str_is(p, ft_isdigit) || check_nb_ant(lem, p))
		end_error(lem, "wrong ant syntax\n");
	p = ft_strchr(p, '\n') + 1;
	while ((str = ft_strchr(p, '\n')))
	{
		*str = '\0';
		if (!ft_strchr(p, '-') && !ft_strchr(p, '#'))
			add_room(p, lem);
		else if (!ft_strcmp(p, "##start"))
			check_com(str + 1, lem->start, lem);
		else if (!ft_strcmp(p, "##end"))
			check_com(str + 1, lem->end, lem);
		else if (ft_strchr(p, '-'))
			break ;
		*str = '\n';
		p = ++str;
	}
	if (!is_tube(p))
		end_error(lem, "Tube are missing\n");
	if (str)
		*str = '\n';
}

/*
**ft_read permet de lire integralement le flux d'entree standard et le stock
**selon sa taille dans buff (<=4096o) ou dans str (>4096o)
*/

void		ft_read(t_lemin *lemin, t_buff *buff)
{
	int		ret;

	ret = 0;
	while ((ret = read(0, buff->buff, BUFF_LEM)))
	{
		buff->buff[ret] = '\0';
		if (!(lemin->str = ft_strjoinfree(lemin->str, buff->buff, 1)))
			end_error(lemin, "Malloc error\n");
		buff->nb++;
	}
	if (lemin->str)
		lemin->ret = lemin->str;
	else
		lemin->ret = buff->buff;
	if (!lemin->ret[0])
		end_error(lemin, "Empty file\n");
}

int			main(int ac, char *av[])
{
	t_lemin		lemin;

	ft_bzero(&lemin, sizeof(lemin));
	pars_arg(&lemin, av, ac);
	ft_read(&lemin, &lemin.buff);
	first_pars(lemin.ret, &lemin);
	if (lemin.start[OCC] != 1 || lemin.end[OCC] != 1)
		end_error(&lemin, "Command missing\n");
	parsing(&lemin);
	solve(&lemin);
	free_gc(lemin.g_c);
	if (lemin.str)
		free(lemin.str);
	return (0);
}
