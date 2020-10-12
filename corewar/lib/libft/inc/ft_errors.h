/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:35:21 by skpn              #+#    #+#             */
/*   Updated: 2020/04/22 18:28:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H
# define FT_ERRORS_H

# define ERR_FD 2

# define ERR_LEN 60
# define ERR_TOTAL_LEN 900

# define ERR_MSG_FULL "Too many errors.\n"
# define ERR_MSG_FULL_LEN 17
# define ERR_TOO_LONG "... (error too long)\n"
# define ERR_TOO_LONG_LEN 21

# define ERRORS_START 500
# define ERR_MALLOC 501

# define ERR_MAGIC_FILE 502

# define ERR_OVERFLOW 503
# define ERR_UNDERFLOW 504

# define ERR_OPEN 505
# define ERR_READ 506
# define ERR_FILE_TOO_LARGE 507

typedef struct	s_err
{
	int			fd;
	int			pos;
	char		*msg;
}				t_err;

int				ft_error(char *new_error);
void			ft_errors_print(void);
void			ft_errors_set_fd(int fd);

#endif
