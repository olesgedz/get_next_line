/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:20:41 by jblack-b          #+#    #+#             */
/*   Updated: 2018/12/13 21:21:57 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 1


int		get_next_line(const int fd, char **line)
{
	int		ret;
	char	buf[BUF_SIZE + 1];

	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (buf[0] == '\n')
		{
			return (0);
		}
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char **a;

	//fd = open(argv[1], O_RDONLY);
	//get_next_line(fd, a);
	//get_next_line(fd, a);
	printf("%d", ft_atoi(" 0 1"));
	return (0);
}
