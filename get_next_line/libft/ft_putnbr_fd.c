/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:08:10 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/05 19:08:11 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	Ecrit l'entier n sur le descipteur de fichier fd.
*/

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	nb = n;
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}
