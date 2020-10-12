/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <jjaegle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:02:53 by jjaegle           #+#    #+#             */
/*   Updated: 2019/10/09 13:34:49 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/ft_printf.h"

# define BUFF_LEM 4096

/*
**----define concernant les tableaux start et end ---
*/
# define OCC 0
# define ID 1
# define DEGREE 2
# define FLAG 3

# define ZER 0
# define END 1

/*
**------define propre au room-------
*/

# define SAME_ID 0
# define DIFF_ID 1
# define NO_ID 2

/*
**------define de simplification de syntaxe---------
*/

# define ROOM(X) X->content_size
# define PATH(X) path->best_path[X - 1]
# define ID_USER(p) lem->tab[p->content_size]->id_user
# define ID_USERNB(p) lem->tab[p]->id_user
# define DISTANCE(p) lem->tab[p->content_size]->distance
# define DISTANCENB(p) lem->tab[p]->distance
# define ASCEND(p) lem->tab[p->content_size]->ascend
# define ASCENDNB(p) lem->tab[p]->ascend
# define PRED(p) lem->tab[p->content_size]->pred
# define PREDNB(p) lem->tab[p]->pred
# define MOORE_PRED(p) lem->tab[p->content_size]->moore_pred
# define MOORE_PREDNB(p) lem->tab[p]->moore_pred
# define MP2(p) lem->tab[p->content_size]->mp2
# define MP2NB(p) lem->tab[p]->mp2
# define START_N(p) lem->tab[p->content_size]->pred == lem->start[ID]
# define START_NB(p) lem->tab[p]->pred == lem->start[ID]
# define VALUE(p) lem->tab[p]->value
# define SECOND(p) lem->tab[p->content_size]->secnd
# define SECONDNB(p) lem->tab[p]->secnd

/*
**-------------------------Structures--------------------
*/

typedef struct		s_list2
{
	size_t			room;
	int				ant;
	struct s_list2	*next;
}					t_list2;

typedef struct		s_path
{
	int				len;
	int				id;
	int				i;
	struct s_path	*next;
	t_list2			*room;
	int				nb_ant;
	int				rounds;
}					t_path;

typedef struct		s_mouv
{
	int				ant;
	int				i;
}					t_mouv;

typedef struct		s_fifo
{
	int				room;
	struct s_fifo	*parent;
	struct s_fifo	*next;
}					t_fifo;

typedef struct		s_room
{
	char			*value;
	int				id_user;
	size_t			pred;
	int				moore_pred;
	int				mp2;
	int				secnd;
	int				distance;
	int				ascend;
	t_fifo			*parent;
	int				id;
	int				x;
	int				y;
}					t_room;

typedef struct		s_buff
{
	char			buff[BUFF_LEM + 1];
	int				i;
	int				nb;
}					t_buff;

typedef struct		s_lemin
{
	t_room			**tab;
	t_buff			buff;
	char			*str;
	int				nb_room;
	int				nb_ant;
	size_t			start[4];
	size_t			end[4];
	char			*ret;
	t_list			**graph;
	t_list			*g_c;
	int				nb_pathmax;
	int				sum_path;
	int				nb_round;
	int				round;
	int				paths;
}					t_lemin;

/*
**---------------------Fn_is-----------------------------
*/

int					is_tube (char *str);
int					is_pst(size_t id, t_list *lst);
int					has_collistion(int id_path, t_list *path, t_room *tab[]);
int					path_ok(int i, t_path paths[2]);

/*
**----------------------Fn_algo-------------------------
*/

void				solve(t_lemin *lem);
void				initialise(t_lemin *lem, int *end, t_fifo **fifo);
void				save_path(t_path paths[2], int nb_path, t_lemin *lem);
t_list2				*extract_path(size_t last, t_lemin *lem, int name);
t_list2				*create_elem(int room, t_lemin *lem);
void				calc_round(t_path *path, int nb_ant, t_lemin *lem,
	int nb_path);
void				print_sol(t_lemin *lem, t_path *box);
void				pars_arg(t_lemin *lem, char *av[], int ac);
int					calc_ant_by_path(t_path *path, int rounds);
void				create_ant(t_list *room, int numant, t_lemin *lem);
void				adjust_path(t_path *path, int nbant);
void				print_round(t_path *path, t_lemin *lem, int *ant);
int					send_pred(t_lemin *lem, int son, int dad);
void				basic_conductor(t_lemin *lem);
void				thread_id(t_fifo *dad, t_lemin *lem, int *end
		, t_fifo *prev);
void				thread_id_to_id(t_list *sons, t_lemin *lem, int *end
	, t_fifo *dad);
void				thread_to_prev(t_list *sons, t_fifo *dad, t_lemin *lem
	, t_fifo *fifo);
void				dad_conductor(t_fifo *son, t_lemin *lem, int *end
	, t_fifo *prev);
void				thread_id_to_noid(t_list *sons, t_lemin *lem, int *end
	, t_fifo *dad);
void				basic_thread(t_list *sons, t_fifo *dad, t_lemin *lem);
int					invalid_pred(t_fifo *son, t_lemin *lem);

/*
**---------------------Hash function-------------------------
*/

int					hash_function(char *str, int nb);
char				*fill_hash(t_list *hash[], char *str, int nb, t_lemin *lem);
int					get_id(t_list *hash[], char *value, int nb);

/*
**---------------------Parsing -------------------------
*/

void				parsing(t_lemin *lemin);
t_room				*create_room(char *str, t_lemin *lem);
int					add_tube(char *str, t_list *hash[], t_lemin *lem);

/*
**----------------------Tools-----------------------------
*/

int					ft_str_is(char *str, int (*f)(int));
int					ft_is_ds(int c);
char				*zap_com(char *str);
void				add_room(char *p, t_lemin *lem);
void				check_room(char *str, t_lemin *lem);
void				ft_path_push(t_path **ad, t_path *new);
int					check_nb_ant(t_lemin *lem, char *nb);

/*
**----------------------------Fn_list--------------------------
*/

t_fifo				*create_fifo_elem(int room, t_lemin *lem);
void				ft_fifo_push(t_fifo **ad, t_fifo *new, t_lemin *lem);
void				ft_sprint_add(t_list2 **ad, t_list2 *new);
int					ft_sprintlen(t_list2 *elem);

/*
**-------------------Gestion Erreur--------------------
*/

void				end_error(t_lemin *lem, char *error);

/*
**--------------------Garbage Collector------------------
*/

void				*malloc_in_gc(size_t size, t_lemin *lem);
void				add_in_gc(void *p, t_lemin *lem);
void				free_gc(t_list *lst);

/*
**----------------------Utility---------------------------
*/

void				print_info(t_list *hash[], t_lemin *lemin, char *av);
void				print_adj(t_lemin *lemin);
void				print_neighb(t_list *oui, t_lemin *lem);
void				print_all_in_one(t_lemin *lem, t_path *path);
void				test(t_lemin *lem, t_path *path);

#endif
