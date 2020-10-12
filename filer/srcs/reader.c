/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <tbrizon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:06:49 by tbrizon           #+#    #+#             */
/*   Updated: 2019/09/11 11:02:16 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** TAKE THE TOKEN SENT BY THE VM
*/

static void		get_piece(char **line, t_filler *filler)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	if (filler->piece)
		free_piece(filler);
	str = ft_strchr(*line, ' ') + 1;
	filler->p_ymax = ft_atoi(str);
	filler->p_xmax = ft_atoi(ft_strchr(str, ' '));
	j = filler->p_ymax;
	ft_strdel(line);
	filler->piece = (char **)malloc(sizeof(char *) * (j + 1));
	while (j--)
	{
		ft_get_next_line(0, line, 0);
		if (**line == '.' || **line == '*')
			filler->piece[++i] = ft_strdup(line[0]);
		ft_strdel(line);
	}
	filler->piece[i + 1] = 0;
}

/*
** COPY THE GAME BOARD
*/

static int		get_board(char **line, t_filler *filler)
{
	int				i;
	int				y;
	char			*str;

	str = ft_strchr(*line, ' ') + 1;
	filler->m_ymax = ft_atoi(str);
	filler->m_xmax = ft_atoi(ft_strchr(str, ' '));
	if (!filler->map)
		malloc_map(filler);
	i = 0;
	y = 0;
	ft_strdel(line);
	while (i < filler->m_ymax)
	{
		ft_get_next_line(0, line, 0);
		if (ft_isdigit(line[0][0]) == 1 && ++y)
			ft_strcpy(filler->map[i++], (*line) + 4);
		if (y == filler->m_ymax)
			break ;
		ft_strdel(line);
	}
	filler->map[filler->m_ymax] = 0;
	create_heatmap(filler);
	ft_strdel(line);
	return (0);
}

/*
** PARSE VM'S INFORMATIONS WITH GET_NEXT_LINE IN ORDER
** TO HAVE THE BOARD AND THE TOKEN TO PLACE
*/

void			start(t_filler *filler)
{
	char	*line;
	int		ret;

	while ((ret = ft_get_next_line(0, &line, 0)))
	{
		if (!line)
			continue ;
		if (ft_strstr(line, "Plateau"))
		{
			get_board(&line, filler);
			ft_strdel(&line);
		}
		else if (ft_strstr(line, "Piece"))
		{
			get_piece(&line, filler);
			solver(filler);
		}
		ft_strdel(&line);
	}
}
