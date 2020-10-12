/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:37:58 by jjaegle           #+#    #+#             */
/*   Updated: 2019/04/12 11:03:25 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static int		is_chars(char c, char chars)
{
	if (c == chars)
		return (1);
	return (0);
}

static int		cmpt_words(char const *str, char chars)
{
	int		i;
	int		cmpt;

	i = 0;
	cmpt = 0;
	while (str[i])
	{
		if (!is_chars(str[i++], chars))
		{
			cmpt++;
			while (!is_chars(str[i], chars) && str[i])
				i++;
		}
	}
	return (cmpt);
}

static char		*next_word(char const *s, int *i, char c)
{
	char	*str;
	int		j;
	int		k;

	j = *i;
	while (s[j] != c && s[j])
		j++;
	if (!(str = malloc(sizeof(char) * (j - *i + 1))))
		return (NULL);
	k = 0;
	while (s[*i] && s[*i] != c)
		str[k++] = s[(*i)++];
	str[k] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		k;

	if (s)
	{
		k = 0;
		i = 0;
		if (!(tab = malloc(sizeof(char*) * (cmpt_words(s, c) + 1))))
			return (NULL);
		while (s[i])
		{
			while (s[i] == c && s[i])
				i++;
			if (s[i])
			{
				if ((tab[k++] = next_word(s, &i, c)) == NULL)
					return (NULL);
			}
		}
		tab[k] = 0;
		return (tab);
	}
	return (NULL);
}
