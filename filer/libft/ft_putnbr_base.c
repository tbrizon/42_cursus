/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:00:20 by tbrizon           #+#    #+#             */
/*   Updated: 2019/06/03 16:00:22 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_base(unsigned long int nb, unsigned int b)
{
	static char			base[] = "0123456789ABCDEF";

	if (nb >= b)
		ft_putnbr_base(nb / b, b);
	ft_putchar(base[nb % b]);
}
