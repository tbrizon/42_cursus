/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:29:37 by jjaegle           #+#    #+#             */
/*   Updated: 2019/04/12 10:41:59 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	ct;
	int		i;

	ct = (char)c;
	i = ft_strlen((char*)s);
	while (i >= 0)
		if (s[i--] == ct)
			return ((char*)&s[i + 1]);
	return (NULL);
}
