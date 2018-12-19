/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:20:41 by jblack-b          #+#    #+#             */
/*   Updated: 2018/12/19 21:07:08 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 30

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
	//temp = ft_strjoin(temp, buf);
	i = 0;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		temp = ft_strjoin((char *)lst->content, buf);
		lst->content = temp;
		printf("%zu %s", i, (char *)lst->content);
		if (ft_strchr((char *)lst->content, '\n'))
			break ;
		i++;
	}

	//ft_strcpy((char *)lst->content, temp);
	//ft_putstr((char *)lst->content);
	//ft_strjoin((char *)lst->content, temp);
	//free(temp);
	*line = (char *)lst->content;
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
