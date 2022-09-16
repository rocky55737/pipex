/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:24:39 by rhong             #+#    #+#             */
/*   Updated: 2022/06/29 17:49:15 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len != 0)
	{
		*(unsigned char *)(b + len - 1) = (unsigned char)c;
		len--;
	}
	return (b);
}

int	ft_strchr(const char *s, int c)
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
	static char	*pre[1];
	char		*ret;
	char		buff[BUFFER_SIZE + 1];
	int			read_flag;

	ret = 0;
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	read_flag = read(fd, buff, BUFFER_SIZE);
	while (read_flag > 0)
	{
		pre[0] = ft_strjoin(pre[0], buff);
		if (ft_strchr(pre[0], '\n') >= 0)
			break ;
		ft_memset(buff, 0, BUFFER_SIZE + 1);
		read_flag = read(fd, buff, BUFFER_SIZE);
	}
	if (pre[0])
	{
		ret = ft_strdup_nl(pre[0]);
		pre[0] = ft_substr_nl(pre[0], ft_strchr(pre[0], '\n') + 1);
	}
	return (ret);
}
