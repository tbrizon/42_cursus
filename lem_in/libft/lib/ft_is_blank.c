/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:40:10 by jjaegle           #+#    #+#             */
/*   Updated: 2019/04/12 11:08:20 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_blank(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}
