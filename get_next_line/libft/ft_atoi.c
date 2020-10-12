/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:21:00 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/05 14:21:01 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The atoi() function converts the initial portion of the string
**	pointed to by str to int representation.
**	-------------------------------------------------------------------------
**	It is equivalent to:
**	(int)strtol(str, (char **)NULL, 10);
**	-------------------------------------------------------------------------
**	While the atoi() function uses the current locale, the atoi_l() function
**	may be passed a locale directly. See xlocale(3) for more information.
**	-------------------------------------------------------------------------
**	IMPLEMENTATION NOTES
**	The atoi() and atoi_l() functions are thread-safe and async-cancel-safe.
**	-------------------------------------------------------------------------
**	The atoi() and atoi_l() functions have been deprecated by strtol()
**	and strtol_l() and should not be used in new code.
*/

int		ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	res;

	res = 0;
	neg = 1;
	i = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == ' ' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res = res + (str[i] - '0');
		i++;
	}
	return (res * neg);
}
