/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:18:13 by jjaegle           #+#    #+#             */
/*   Updated: 2019/05/07 15:06:22 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinfree(char *s, char *t)
{
	char *str;

	if (!s)
		str = ft_strdup(t);
	else
	{
		str = ft_strjoin(s, t);
		s = my_free(s);
	}
	return (str);
}
