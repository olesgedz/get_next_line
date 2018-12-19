/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:20:41 by jblack-b          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/12/16 21:28:22 by jblack-b         ###   ########.fr       */
=======
/*   Updated: 2018/12/19 18:05:27 by olesgedz         ###   ########.fr       */
>>>>>>> 753f49f4374e444f8743f3906b34940e2d9fb0d9
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
	size_t i;
	char* temp;
	i = 0;
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (!(lst))
	{
		lst = malloc(sizeof(t_list));
		MALLOC_CHECK(lst->content = malloc(sizeof(char) * (ret + 1)));
	}
	//*(char *)(lst->content) = 'L';

	//printf("%c", *(char *)(lst->content));
<<<<<<< HEAD
	ft_memcpy((char *)lst->content, buf, ret + 1);
	lst->content = ft_memchr((char *)lst->content, '\n', ret - 1) + 1;
=======
	//temp = ft_strjoin(temp, buf);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_strcpy((char *)lst->content, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}

	//ft_putstr((char *)lst->content);
	//ft_strjoin((char *)lst->content, temp);
	//free(temp);

>>>>>>> 753f49f4374e444f8743f3906b34940e2d9fb0d9
	*line = lst->content;
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char *a;
	if (argc != 2)
	{
		ft_putstr("ERROR");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &a);
	ft_putendl(a);
	//get_next_line(fd, &a);
	//ft_putstr(a);
	return (0);
}
