/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:55:12 by tbrizon           #+#    #+#             */
/*   Updated: 2019/06/03 15:55:14 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_makestr(size_t size, char c)
{
	char	*str;

	str = ft_strnew(size);
	ft_memset((void*)str, c, size);
	return (str);
}
