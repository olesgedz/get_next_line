/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 23:15:52 by jblack-b          #+#    #+#             */
/*   Updated: 2018/12/26 01:39:08 by olesgedz         ###   ########.fr       */
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
		ft_strclr((char *)(*list)->content);
		free((*list)->content);
		(*list)->content = NULL;
	}
	free(*list);
}

void		ft_lstdelmid(t_list **begin, t_list **list)
{
	t_list *temp;
	t_list *join;

	temp = *begin;
	if (temp != NULL && temp == &(**list))
	{
		*begin = (*begin)->next;

	}else
	{
	while (temp != NULL && temp->next)
	{
		if (temp->next == &(**list))
		{
			join = temp->next->next;
			ft_lstdel_u(&temp->next);
			temp->next = join;
		}
		temp = temp->next;
	}
}
	if (temp == NULL) return;
}

void deleteNode(t_list **head_ref, t_list **list)
{
    // Store head node
    t_list *temp = *head_ref;
		t_list *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->next == &(**list))
    {
        *head_ref = temp->next;   // Changed head
        free(temp);               // free old head
        return;
    }
    while (temp != NULL && temp->next != &(**list))
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

int main()
{
	t_list *lst;
	t_list * temp;
	lst = ft_lstnew("hello", 6);
	temp = lst;
	ft_lstadd(&lst, ft_lstnew("darkness", 8));
	t_list *a = ft_lstnew("my", 8);
	ft_lstadd(&lst, a);
	ft_lstadd(&lst, ft_lstnew("old", 8));
	ft_lstadd(&lst, ft_lstnew("friend", 8));
	ft_lstdelmid(&lst, &temp);
		ft_lstprint(lst);
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
