/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaye <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:53:41 by yaye              #+#    #+#             */
/*   Updated: 2019/06/13 14:53:41 by yaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define TUMOR '!'

/*
** --------------------------- EXTERNAL HEADERS -------------------------------
*/

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

/*
** ------------------------------ STRUCTURES ----------------------------------
*/

typedef struct		s_bloc
{
	int		x;
	int		y;
}					t_bloc;

typedef struct		s_tris
{
	int		pos;
	char	letter;
	t_bloc	bloc[4];
}					t_tris;

typedef struct		s_board
{
	char	*str;
	int		size;
	int		lsiz;
	int		n;
}					t_board;

/*
** ---------------------------- MAIN FUNCTIONS --------------------------------
*/

void				fillit(int fd, t_list *lst);
void				solve(t_board *board, t_list *lst, t_list *lcur);
int					scan(char *str, int size);

/*
** -------------------------------- UTILITY -----------------------------------
*/

void				ft_lstaddbel(t_list **alst, t_list *new);
void				fillfree(t_list **lst);
void				resize(t_board *board, t_list *lst);
void				norminette(int cmpt, t_board *board, t_list *lst);
int					weight(t_list *lst);
int					set_to(t_board *board, t_tris *tetris);

#endif
