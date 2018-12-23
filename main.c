/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:20:41 by jblack-b          #+#    #+#             */
/*   Updated: 2018/12/23 20:25:17 by jblack-b         ###   ########.fr       */
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
	tmp = *file;
	return (tmp);
}

/*int		get_next_line(const int fd, char **line)
{
	int						ret;
	char					buf[BUF_SIZE + 1];
	static				t_list *lst;
	//t_list 							*lst;
	int						i;

	//lst = file;
	if (!lst)
		MALLOC_CHECK(lst = ft_lstnew("", fd));
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (!(lst->content))
			MALLOC_CHECK(lst->content = malloc(sizeof(char) * (ret + 1)));
		buf[ret] = '\0';
		lst->content = ft_strjoin((char *)lst->content, buf);
		if (ft_strchr((char *)lst->content, '\n'))
			break ;
	}
	if (ret == 0 && !*(char *)lst->content)
		return (0);
	*line = ft_strsub((char *)lst->content, 0,\
	ft_strchr((char *)lst->content, '\n') - (char *)lst->content);
	i = ft_strchr((char *)lst->content, '\n') - (char *)lst->content;
	(i < (int)ft_strlen((char *)lst->content))\
	? lst->content += (i + 1) : ft_strclr((char *)lst->content);
	ft_putstr(*line);
	return (1);
}*/

t_list	*ft_getfile(t_list **file, int fd)
{

	if (!*file)
		MALLOC_CHECK_NULL(*file = ft_lstnew("", fd));
	while (*file && (*file)->content_size != fd)
		*file = (*file)->next;
	if ((*file)->content_size != fd)
	{
		ft_lstadd(file,  ft_lstnew("", fd));
		*file = (*file)->next;
	}
	return (*file);
}

int		get_next_line(const int fd, char **line)
{
	int						ret;
	//char					buf[BUF_SIZE + 1];
	static				t_list *file;
	t_list *lst;
	int i;
	char *temp;
	char *temp2;
	char *buf;

	buf = malloc(BUF_SIZE + 1);
//	t_list *lst;

/*	if (!buf)
		MALLOC_CHECK_INT(buf = malloc(sizeof(char *) * BUF_SIZE + 1 // doent work
*/
	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);

	lst = ft_getfile(&file, fd);
	//lst = file;
	/*if (!lst)
		MALLOC_CHECK_INT(lst = ft_lstnew("", fd));
	*/
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (!(lst->content))
			MALLOC_CHECK_INT(lst->content = malloc(sizeof(char) * (ret + 1)));
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
	temp2 = *line;
	*line = ft_strsub((char *)lst->content, 0,\
	ft_strchr((char *)lst->content, '\n') - (char *)lst->content);
	i = ft_strchr((char *)lst->content, '\n') - (char *)lst->content;
	free(temp2);
	temp2 =  lst->content;
	//(i < (int)ft_strlen((char *)lst->content)) ? lst->content += (i + 1) : ft_strclr((char *)lst->content);
	(i < (int)ft_strlen((char *)lst->content)) ?\
	lst->content = ft_strdup((char *)lst->content + i + 1) : ft_strclr((char *)lst->content);
	free(temp2);
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
	int a = fd;
	get_next_line(fd, &line);
	ft_putstr(line);
	get_next_line(fd2, &line);
	ft_putstr(line);
	get_next_line(fd, &line);
	ft_putstr(line);
	get_next_line(fd2, &line);
	ft_putstr(line);
	get_next_line(fd, &line);
	ft_putstr(line);
	get_next_line(fd2, &line);
	ft_putstr(line);
	/*while (get_next_line(a, &line))
	{
		ft_putstr(line);
		ft_putstr("\n");
		if (a == fd)
			a = fd2;
		else
			a = fd;
	}*/
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
