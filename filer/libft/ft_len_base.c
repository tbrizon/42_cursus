/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:16:55 by tbrizon           #+#    #+#             */
/*   Updated: 2019/05/14 15:16:57 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Return the size of an int depending on the base
*/

int		ft_len_base(long long int nb, int base)
{
	int				i;
	int				signe;

	signe = (nb > 0) ? 0 : 1;
	i = 1;
	while ((nb = nb / base))
		i++;
	return (i + signe);
}
