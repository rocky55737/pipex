/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:15:28 by rhong             #+#    #+#             */
/*   Updated: 2022/10/02 15:21:39 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len != 0)
	{
		*(unsigned char *)(b + len - 1) = (unsigned char)c;
		len--;
	}
	return (b);
}

static int	my_strchr(const char *s, int c)
{
	int	ret;

	ret = 0;
	while (s[ret])
	{
		if (s[ret] == c)
			return (ret);
		ret++;
	}
	if (c == 0)
		return (ret);
	return (-1);
}

char	*ft_strdup_nl(const char *src)
{
	int		src_len;
	char	*duped_str;

	src_len = 0;
	while (src[src_len] && src[src_len] != '\n')
		src_len++;
	if (src[src_len] == '\n')
		src_len++;
	if (src_len == 0)
		return (0);
	duped_str = (char *)malloc(sizeof(char) * (src_len + 1));
	if (duped_str == 0)
		return (0);
	duped_str[src_len] = 0;
	while (0 < src_len)
	{
		duped_str[src_len - 1] = src[src_len - 1];
		src_len--;
	}
	return (duped_str);
}

char	*get_next_line(int fd)
{
	static char	*pre[OPEN_MAX];
	char		*ret;
	char		buff[BUFFER_SIZE + 1];
	int			read_flag;

	ret = 0;
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	read_flag = read(fd, buff, BUFFER_SIZE);
	while (read_flag > 0)
	{
		pre[fd] = ft_strjoin(pre[fd], buff);
		if (my_strchr(pre[fd], '\n') >= 0)
			break ;
		ft_memset(buff, 0, BUFFER_SIZE + 1);
		read_flag = read(fd, buff, BUFFER_SIZE);
	}
	if (pre[fd])
	{
		ret = ft_strdup_nl(pre[fd]);
		pre[fd] = ft_substr_nl(pre[fd], my_strchr(pre[fd], '\n') + 1);
	}
	return (ret);
}
