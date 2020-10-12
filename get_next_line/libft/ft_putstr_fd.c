/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:02:32 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/05 19:02:33 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
**		DESCRIPTION
**	Ecrit la chaine s sur le descripteur de fichier fd.
*/

void	ft_putstr_fd(char const *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
