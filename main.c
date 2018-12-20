/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:20:41 by jblack-b          #+#    #+#             */
/*   Updated: 2018/12/20 18:30:46 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 15

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
char	*ft_strjoinch(char const *s1, char c)
{
	char	*new_str;
	size_t	i;
	size_t	s1_len;

	if (!s1 || !c)
		return (NULL);
	s1_len = ft_strlen(s1);
	new_str = ft_strnew(s1_len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		*(new_str + i) = *(s1 + i);
	*(new_str + i) = c;
	return (new_str);
}

int			ft_copyuntil(char **dst, char *src, char c)
{
	int		i;
	int		count;
	int		pos;

	i = -1;
	count = 0;
	while (src[++i])
		if (src[i] == c)
			break ;
	pos = i;
	if (!(*dst = ft_strnew(i)))
		return (0);
	while (src[count] && count < i)
	{
		if (!(*dst = ft_strjoinch(*dst, src[count])))
			return (0);
		count++;
	}
	return (pos);
}

int		get_next_line(const int fd, char **line)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	static t_list *lst;
	char* temp;
	int i = 0;
	if (!lst)
		MALLOC_CHECK(lst = ft_lstnew(NULL, 0));
	ft_putstr((char *)(lst->content));
	//*(char *)(lst->content) = 'L';

	//printf("%c", *(char *)(lst->content));
	//temp = ft_strjoin(temp, buf);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (!(lst->content))
			MALLOC_CHECK(lst->content = malloc(sizeof(char) * (ret + 1)));
		buf[ret] = '\0';
		lst->content = ft_strjoin((char *)lst->content, buf);
		if (ft_strchr((char *)lst->content, '\n'))
			break ;
	}
	i = ft_copyuntil(line, (char *)lst->content, '\n');
		(i < (int)ft_strlen((char *)lst->content))
	? lst->content += (i + 1)
	: ft_strclr((char *)lst->content);
		/*line = ft_strsub((char *)lst->content, 0,\
		ft_strchr((char *)lst->content, '\n') - (char *)lst->content);
		lst->content = (char *)lst->content + ft_strlen(*line);
		ft_putstr((char *)lst->content);*/
	//lst->content = (char *) ft_strchr((char *)lst->content, '\n') + 1;
	//ft_strcpy((char *)lst->content, temp);
	//ft_putstr((char *)lst->content);
	//ft_strjoin((char *)lst->content, temp);
	//free(temp);
		//ft_putendl((char *)lst->content);
		//*line = ft_strjoin(ft_strchr((char *)lst->content, '\n') + 1, ft_strsub((char *)lst->content, 0,\
			ft_strchr((char *)lst->content, '\n') - (char *)lst->content));

		/*	ft_putendl(ft_strsub((char *)lst->content, 0,  ft_strchr((char *)lst->content, '\n') - (char *)lst->content));
		lst->content = ft_strjoin(ft_strsub((char *)lst->content, 0,  ft_strchr((char *)lst->content, '\n') - (char *)lst->content), \
		ft_strsub((char *)lst->content, ft_strchr((char *)lst->content, '\n') - (char *)lst->content,\
		ft_strchr((char *)lst->content, '\0') - (char *)lst->content));*/
		//ft_putstr(ft_strchr((char *)lst->content, '\n') + 1);
		//ft_putendl(ft_strsub(ft_strchr((char *)lst->content, '\n') + 1, 0, ft_strlen((char *)lst->content)));
		//ft_putstr((char *)(lst->content));
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
	get_next_line(fd, &a);
	ft_putendl(a);
	get_next_line(fd, &a);
	ft_putendl(a);
	return (0);
}
