/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <tbrizon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 14:13:57 by tbrizon           #+#    #+#             */
/*   Updated: 2019/09/11 11:03:09 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	malloc_map(t_filler *filler)
{
	int i;

	i = 0;
	filler->map = (char **)malloc(sizeof(char *) * (filler->m_ymax + 1));
	while (i < filler->m_ymax)
	{
		filler->map[i] = (char *)malloc(sizeof(char) * (filler->m_xmax + 1));
		filler->map[i++][filler->m_xmax] = '\0';
	}
	filler->map[filler->m_ymax] = 0;
}

int		main(void)
{
	t_filler	filler;
	char		*line;

	init(&filler);
	if (ft_get_next_line(0, &line, 0) && line && ft_strstr(line, "$$$ exec"))
	{
		(ft_strstr(line, "p1")) ? filler.letter_me = 'O'
		: (filler.letter_enemy = 'O');
		ft_strdel(&line);
		start(&filler);
	}
	else
		ERROR;
	free_filler(&filler);
	ft_get_next_line(0, &line, 1);
	return (0);
}
