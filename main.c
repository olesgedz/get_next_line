/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:20:41 by jblack-b          #+#    #+#             */
/*   Updated: 2018/12/23 22:15:51 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 10

static t_list			*get_correct_file(t_list **file, int fd)
{
	t_list				*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	//tmp = *file;
	return (tmp);
}

t_list	*ft_getfile(t_list **file, int fd)
{
	t_list *tmp;


	tmp = *file;
	while (tmp)
	{
		if (tmp->content_size == fd)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	if (!tmp)
		MALLOC_CHECK_NULL(tmp = ft_lstnew("", fd));
	ft_lstadd(file, tmp);
	tmp = *file;


	/*while (*file && (*file)->content_size != fd)
		*file = (*file)->next;
	if ((*file)->content_size != fd)
	{
		ft_lstadd(file, ft_lstnew("", fd));
		*file = (*file)->next;
	}
	return (*file);*/
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	int						ret;
	static				t_list *file;
	t_list *lst;
	int i;
	char *temp;
	char *buf;

	MALLOC_CHECK_INT(buf = malloc(BUF_SIZE + 1));
	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	lst = ft_getfile(&file, fd);
	//printf()
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
	//	if (!(lst->content))
		//	MALLOC_CHECK_INT(lst->content = malloc(sizeof(char) * (ret + 1)));
		buf[ret] = '\0';
		temp = (char *)lst->content;
		lst->content = ft_strjoin((char *)lst->content, buf);
		free(temp);
		if (ft_strchr((char *)lst->content, '\n'))
			break ;
	}
	free(buf);
	if (ret == 0 && !*(char *)lst->content)
	{
		free(lst->content);
		free(lst);
		return (0);
	}
	temp = *line;
	*line = ft_strsub((char *)lst->content, 0,\
	ft_strchr((char *)lst->content, '\n') - (char *)lst->content);
	i = ft_strchr((char *)lst->content, '\n') - (char *)lst->content;
	free(temp);
	temp = lst->content;
	(i < (int)ft_strlen((char *)lst->content)) ? lst->content = \
	ft_strdup((char *)lst->content + i + 1) : ft_strclr((char *)lst->content);
	free(temp);
	return (1);
}

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
		//printf("%d, %d\n", fd, fd2);
		get_next_line(fd2, &line);
		ft_putstr(line);
		get_next_line(fd2, &line);
		ft_putstr(line);
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

	/*static t_list *file;
	t_list *temp;
	temp = ft_getfile(&file, 1);
	temp->content = ft_strjoin((char *)temp->content, "TEN");
	temp = ft_getfile(&file, 4);
	temp->content = ft_strjoin((char *)temp->content, "ELEVEN");
	ft_lstprint(file);*/
	return (0);
}
