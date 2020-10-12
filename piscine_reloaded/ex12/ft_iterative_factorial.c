/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:32:06 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/01 14:45:59 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_iterative_factorial(int nb)
{
	int i;

	i = nb - 1;
	if (nb > 12 || nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	while (i > 1)
	{
		nb = nb * i;
		i--;
	}
	return (nb);
}
