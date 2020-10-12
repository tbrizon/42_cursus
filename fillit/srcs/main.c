/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaye <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:57:06 by yaye              #+#    #+#             */
/*   Updated: 2019/06/15 15:57:07 by yaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int ac, char **av)
{
	t_list	*lst;
	int		fd;

	lst = NULL;
	if (ac != 2)
	{
		ft_putstr("USAGE: 1 TETRIMINOS FILE IN ENTRY\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	fillit(fd, lst);
	return (1);
}
