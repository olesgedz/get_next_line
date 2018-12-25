/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 23:15:52 by jblack-b          #+#    #+#             */
/*   Updated: 2018/12/25 21:31:17 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void		ft_lstdel_u(t_list **list)
{
	if (*list)
	{
		ft_strclr((char *)lst->content);
		free(list->content);
		
	}
}

void		ft_lstdelmid(t_list **begin, t_list **list)
{
	t_list *temp;

	temp = *begin;
	while (temp->next)
	{
		if (temp->next == &(**list))
		{

		}
		temp = temp->next;
	}
}

int main()
{
	t_list *lst;

	lst = ft_lstnew("hello", 6);
	ft_lstadd(&lst, ft_lstnew("darkness", 8));
	t_list *a = ft_lstnew("my", 8);
	ft_lstadd(&lst, a);
	ft_lstadd(&lst, ft_lstnew("old", 8));
	ft_lstadd(&lst, ft_lstnew("friend", 8));
	//ft_lstprint(lst);
	ft_lstdelmid(&lst, &a);
	return (0);
}


/*int		main(int argc, char **argv)
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
		while (get_next_line(fd, &line))
		{
			ft_putstr(line);
			free(line);
			ft_putstr("\n");
		}
	}
	return (0);
}*/
