/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 23:15:52 by jblack-b          #+#    #+#             */
/*   Updated: 2018/12/24 19:01:48 by olesgedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	int fd3;
	char	*line;


	if (argc < 2)
	{
		ft_putstr("ERROR");
		return (0);
	}
	if (argc > 2)
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		fd3 =  open(argv[3], O_RDONLY);
		//printf("%d, %d\n", fd, fd2);
		get_next_line(fd3, &line);
		ft_putstr(line);
		ft_putstr("\n");
		get_next_line(fd, &line);
		ft_putstr(line);
		ft_putstr("\n");
		get_next_line(fd2, &line);
		ft_putstr(line);
		ft_putstr("\n");
		get_next_line(fd, &line);
		ft_putstr(line);
		ft_putstr("\n");
		get_next_line(fd2, &line);
		ft_putstr(line);
		ft_putstr("\n");
		get_next_line(fd, &line);
		ft_putstr(line);
		ft_putstr("\n");
		get_next_line(fd3, &line);
		ft_putstr(line);
		ft_putstr("\n");
		get_next_line(fd3, &line);
		ft_putstr(line);
		ft_putstr("\n");

	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			ft_putstr(line);
			ft_putstr("\n");
		}
	}
	free(line);
	return (0);
}
