/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:20:41 by jblack-b          #+#    #+#             */
/*   Updated: 2018/12/16 21:00:24 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 100

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
	size_t i;

	i = 0;
	lst = malloc(sizeof(t_list));
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	ft_putstr(buf);
	lst->content = malloc(sizeof(ret * sizeof(char)));
	//*(char *)(lst->content) = 'L';
	//printf("%c", *(char *)(lst->content));
	//ft_memcpy((char *)lst->content, buf, ret - 1);
	//ft_putstr(lst->content);
	//*line = lst->content;
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char **a;
	if (argc != 2)
	{
		ft_putstr("ERROR");
		return (NULL);
	}
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, a);
	//ft_putstr(*a);
	return (0);
}
