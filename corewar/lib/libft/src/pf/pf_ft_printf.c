/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikpenou <sikpenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:01:51 by sikpenou          #+#    #+#             */
/*   Updated: 2020/03/04 14:38:11 by sikpenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int		ft_sprintf(char **str, char *format, ...)
{
	t_pf	pf;

	ft_memset(&pf, 0, sizeof(pf));
	pf.format = format;
	va_start(pf.ap, format);
	if (core_pf_2(&pf) != EXIT_SUCCESS)
		pf.size = -1;
	*str = pf.str;
	return (pf.pos);
}

int		ft_dprintf(int fd, char *format, ...)
{
	t_pf	pf;

	if (fd < 0)
		return (0);
	ft_memset(&pf, 0, sizeof(pf));
	pf.format = format;
	pf.fd = fd;
	va_start(pf.ap, format);
	if (core_pf_2(&pf) == EXIT_SUCCESS)
		write(pf.fd, pf.str, pf.pos);
	else
		pf.size = -1;
	easyfree((void **)&pf.str);
	return (pf.pos);
}

int		ft_printf(char *format, ...)
{
	t_pf	pf;

	ft_memset(&pf, 0, sizeof(pf));
	pf.format = format;
	pf.fd = 1;
	va_start(pf.ap, format);
	if (core_pf_2(&pf) == EXIT_SUCCESS)
		write(pf.fd, pf.str, pf.pos);
	else
		pf.size = -1;
	easyfree((void **)&pf.str);
	return (pf.pos);
}
