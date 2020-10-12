/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:04:13 by tbrizon           #+#    #+#             */
/*   Updated: 2019/05/03 16:34:04 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 8

int		get_next_line(int fd, char **line);

#endif
