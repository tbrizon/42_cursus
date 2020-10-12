/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaegle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:44:33 by jjaegle           #+#    #+#             */
/*   Updated: 2019/06/11 09:11:16 by jjaegle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			color(const char **format)
{
	int size;
	int cmpt;

	cmpt = 0;
	if (!ft_strncmp(*format, "{red}", (size = 5)))
		cmpt = ft_printf("%s", PF_RED);
	else if (!ft_strncmp(*format, "{purple}", (size = 8)))
		cmpt = ft_printf("%s", PF_PURPLE);
	else if (!ft_strncmp(*format, "{yellow}", (size = 8)))
		cmpt = ft_printf("%s", PF_YELLOW);
	else if (!ft_strncmp(*format, "{blue}", (size = 6)))
		cmpt = ft_printf("%s", PF_BLUE);
	else if (!ft_strncmp(*format, "{green}", (size = 7)))
		cmpt = ft_printf("%s", PF_GREEN);
	else if (!ft_strncmp(*format, "{cyan}", (size = 6)))
		cmpt = ft_printf("%s", PF_CYAN);
	else if (!ft_strncmp(*format, "{white}", (size = 7)))
		cmpt = ft_printf("%s", PF_WHITE);
	else if (!ft_strncmp(*format, "{eoc}", (size = 5)))
		cmpt = ft_printf("%s", PF_EOC);
	if (cmpt != 0)
		*format = (*format) + size;
	return ((**format == '\0') ? cmpt - 1 : cmpt);
}

int			ft_printf(const char *format, ...)
{
	t_bloc	bdi;
	t_buf	buf;
	va_list	ap;

	initialise_bloc(&bdi);
	initialise_buf(&buf);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '{')
			buf.cmpt += color(&format);
		if (*format != '%' && *format != '\0')
			char_buf(&buf, *format, 1);
		else if (*format != '\0')
		{
			buf.cmpt += ft_parsing(&format, &bdi, &buf, ap);
			if (bdi.type)
				dispatcher(&bdi, ap, &buf);
			continue ;
		}
		format++;
	}
	empty_buf(&buf);
	va_end(ap);
	return (buf.cmpt);
}
