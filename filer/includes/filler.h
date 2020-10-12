/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <tbrizon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:03:34 by tbrizon           #+#    #+#             */
/*   Updated: 2019/09/11 11:38:20 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define ME -1
# define ENEMY 1
# define ERROR ft_putendl("input error")

/*
** --------------------------- EXTERNAL HEADERS -------------------------------
*/

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

/*
** ------------------------------ STRUCTURES ----------------------------------
*/

typedef struct		s_filler
{
	int				m_ymax;
	int				m_xmax;
	int				m_size;
	char			**piece;
	int				**hmap;
	char			**map;
	int				p_xmax;
	int				p_ymax;
	char			letter_me;
	char			letter_enemy;
	int				fd;
	int				hmap_count;
	int				best_pos[2];
	int				m_dir[4];
	int				e_dir[4];
	int				returnvalue;
}					t_filler;

typedef struct		s_token
{
	int				p_y;
	int				p_x;
	int				f;
	int				r;
}					t_token;

/*
** -------------------------------- UTILITY -----------------------------------
*/

int					main();
void				pboard_info(t_filler *filler);
void				start(t_filler *filler);
void				solver(t_filler *filler);
void				create_heatmap(t_filler *filler);

/*
** -------------------------------- TOOLS -------------------------------------
*/

void				init(t_filler *filler);
void				re_init(int *direction);
int					wich_dir(t_filler *filler);
void				re_initcount(t_filler *filler);
void				init_tok(t_token *t);
void				direction(t_filler *filler, int *direction, int y, int x);
void				malloc_hm(t_filler *filler);
void				malloc_map(t_filler *filler);
void				what_todo(t_filler *filler, int y, int x);
void				free_piece(t_filler *filler);
void				free_filler(t_filler *filler);
void				malloc_map(t_filler *filler);

#endif
