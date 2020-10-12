/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:59:09 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/01 18:59:11 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	display(char *filename)
{
	int		fd;
	char	c;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ;
	while (read(fd, &c, 1) != 0)
		write(1, &c, 1);
	close(fd);
}

int		main(int ac, char **av)
{
	if (ac == 1)
		ft_putstr("File name missing.\n");
	else if (ac > 2)
		ft_putstr("Too many arguments.\n");
	else
		display(av[1]);
	return (0);
}
