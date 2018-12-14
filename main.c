/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:20:41 by jblack-b          #+#    #+#             */
/*   Updated: 2018/12/14 22:06:47 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 10

int		ft_check_buff(char *buf, int ret)
{
	int i;

	i = 0;
	while (i < ret)
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
int		get_next_line(const int fd, char **line)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	static t_list *lst;

	lst = malloc((sizeof(t_list)));
	ret = read(fd, buf, BUF_SIZE);
	lst = ft_lstnew(buf, ret);
	ret = read(fd, buf, BUF_SIZE);
	lst->content = ft_memccpy(lst->content, buf, '\n', ret);

	ft_putstr(line);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char **a;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, a);
	get_next_line(fd, a);

	return (0);
}
