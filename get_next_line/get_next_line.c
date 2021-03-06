/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:06:47 by tbrizon           #+#    #+#             */
/*   Updated: 2019/05/03 18:21:39 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_copy_line(char *str, char **line)
{
	int				i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
			break ;
	}
	*line = ft_strsub(str, 0, i);
	return (i);
}

t_list		*ft_check_fd(int fd, t_list **lst)
{
	t_list			*tmp;

	tmp = *lst;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = ft_lstnew("\0", fd)))
		return (NULL);
	ft_lstadd(lst, tmp);
	return (tmp);
}

t_list		*ajust_str(t_list *buff, int i)
{
	char			*tmp;

	if (i < ((int)ft_strlen(buff->content)))
	{
		tmp = buff->content;
		buff->content = ft_strdup(buff->content + 1 + i);
		ft_strdel(&tmp);
	}
	else
		ft_strclr(buff->content);
	return (buff);
}

int			get_next_line(int fd, char **line)
{
	t_list			*buff;
	static t_list	*lst;
	int				i;
	char			tmp[BUFF_SIZE + 1];

	i = 0;
	if (BUFF_SIZE <= 0)
		return (-1);
	if (fd < 0 || line == NULL || read(fd, tmp, 0) < 0)
		return (-1);
	if (!(buff = ft_check_fd(fd, &lst)))
		return (-1);
	while ((i = read(fd, tmp, BUFF_SIZE)))
	{
		tmp[i] = 0;
		buff->content = ft_strjoinfree(buff->content, tmp, 1);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	if (!ft_strlen(buff->content))
		return (0);
	i = ft_copy_line(buff->content, line);
	ajust_str(buff, i);
	return (1);
}
