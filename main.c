/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:20:41 by jblack-b          #+#    #+#             */
/*   Updated: 2018/12/20 21:38:13 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 10

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUF_SIZE + 1];
	static		t_list *lst;
	char			*temp;
	int				i;

	if (!lst)
		MALLOC_CHECK(lst = ft_lstnew("", fd));
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (!(lst->content))
			MALLOC_CHECK(lst->content = malloc(sizeof(char) * (ret + 1)));
		buf[ret] = '\0';
		lst->content = ft_strjoin((char *)lst->content, buf);
		if (ft_strchr((char *)lst->content, '\n'))
			break ;
	}
	if (ret == 0 && !*(char *)lst->content)
		return (0);
	*line = ft_strsub((char *)lst->content, 0,\
	ft_strchr((char *)lst->content, '\n') - (char *)lst->content);
	i = ft_strchr((char *)lst->content, '\n') - (char *)lst->content;
	(i < (int)ft_strlen((char *)lst->content))\
	? lst->content += (i + 1) : ft_strclr((char *)lst->content);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char *line;
	if (argc != 2)
	{
		ft_putstr("ERROR");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_putstr(line);
		ft_putstr("\n");
	}
	return (0);
}
