/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:20:41 by jblack-b          #+#    #+#             */
/*   Updated: 2018/12/25 00:32:21 by olesgedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

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
	return (tmp);
}

char	*retrive_line(char *content)
{
	char	*line;
	size_t	len;

	if (ft_strchr(content, '\n'))
	{
		len = ft_strchr(content, '\n') - content;
		line = ft_strncpy(ft_strnew(len), content, len);
		content += (len + 1);
	}
	else
	{
		len = ft_strlen(content);
		line = ft_strncpy(ft_strnew(len), content, len);
		content += len;
	}
	return (line);
}

int		get_next_line(const int fd, char **line)
{
	int						ret;
	static				t_list *file;
	t_list *lst;
	int i;
	char *temp;
	char *buf;


	buf = NULL;
	MALLOC_CHECK_INT(buf = malloc(BUFF_SIZE + 1));
	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE < 1)
		return (-1);

	lst = ft_getfile(&file, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		temp = (char *)lst->content;
		lst->content = ft_strjoin((char *)lst->content, buf);
		//ft_putstr((char *)lst->content);
		free(temp);
		if (ft_strchr((char *)lst->content, '\n'))
			break ;
	}
	free(buf);
/*	if (ret == 0 && !*(char *)lst->content)
	{
		free(lst->content);
		free(lst);
		return (0);
	}*/
	if (ret < BUFF_SIZE && !ft_strlen((char *)lst->content))
		return (0);
if (ft_strchr((char *)lst->content, '\n'))
{
	temp = *line;
	*line = ft_strsub((char *)lst->content, 0,\
	ft_strchr((char *)lst->content, '\n') - (char *)lst->content);
	i = ft_strchr((char *)lst->content, '\n') - (char *)lst->content;
	free(temp);
	temp = lst->content;
	(i < (int)ft_strlen((char *)lst->content)) ? lst->content = \
	ft_strdup((char *)lst->content + i + 1) : ft_strclr((char *)lst->content);
	free(temp);
}
else
{
	i = ft_strlen((char *)lst->content);
	*line = ft_strncpy(ft_strnew(i), (char *)lst->content, i);
	lst->content =  ft_strdup((char *)lst->content + i);
	//ft_strclr((char *)lst->content);
//	free((char *)lst->content);
}
	//*line = retrive_line((char *)lst->content);
	return (1);
}
