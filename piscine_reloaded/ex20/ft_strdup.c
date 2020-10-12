/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:38:32 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/01 16:59:41 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = -1;
	dup = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	while (src[++i] != '\0')
		dup[i] = src[i];
	dup[i] = '\0';
	return (dup);
}
