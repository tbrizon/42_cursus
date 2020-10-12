/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:55:24 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/05 18:55:25 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
**		DESCRIPTION
**	Ecrit le caractere c sur le descripteur de fichier fd.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
