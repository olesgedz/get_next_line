/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 23:15:52 by jblack-b          #+#    #+#             */
/*   Updated: 2019/01/07 19:57:52 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
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
		int i = fd;
		while (get_next_line(i, &line))
		{
			ft_putstr(line);
			free(line);
			ft_putstr("\n");
			if (i == fd)
				i = fd2;
			else
				i = fd;
		}
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) > 0)
		{
			ft_putstr(line);
			free(line);
			ft_putstr("\n");
		}
	}
	return (0);
}
