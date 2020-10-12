/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:00:54 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/01 17:35:29 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*tab_int;
	int i;
	int size;

	i = 0;
	size = max - min;
	if (min >= max)
		return (0);
	else
		tab_int = (int *)malloc(sizeof(tab_int) * (size));
	while (min < max)
	{
		tab_int[i] = min;
		i++;
		min++;
	}
	return (tab_int);
}
