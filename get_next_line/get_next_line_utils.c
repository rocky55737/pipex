/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:22:49 by rhong             #+#    #+#             */
/*   Updated: 2022/06/29 17:17:28 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	my_strlen(char const *str)
{
	size_t	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_index;
	int	src_index;

	dest_index = 0;
	src_index = 0;
	while (dest[dest_index])
		dest_index++;
	while (src[src_index])
	{
		dest[dest_index + src_index] = src[src_index];
		src_index++;
	}
	dest[dest_index + src_index] = 0;
	return (dest);
}

size_t	ft_strcpy(char *dest, char *src)
{
	size_t	len;
	size_t	counter;

	counter = 0;
	len = my_strlen(src);
	while (counter < len)
	{
		dest[counter] = src[counter];
		counter++;
	}
	dest[counter] = 0;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*joined_str;

	if (s1)
		len_s1 = my_strlen(s1);
	else
		len_s1 = 0;
	len_s2 = my_strlen(s2);
	joined_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (joined_str == 0)
		return (0);
	if (s1)
	{
		ft_strcpy(joined_str, (char *)s1);
		free(s1);
	}
	else
		joined_str[0] = 0;
	ft_strcat(joined_str, (char *)s2);
	return (joined_str);
}

char	*ft_substr_nl(char *s, int start)
{
	char	*sub_string;
	size_t	cnt;
	size_t	s_len;

	if (!start)
	{
		free(s);
		return (0);
	}
	s_len = my_strlen(s);
	sub_string = (char *)malloc(sizeof(char) * (s_len - start + 1));
	if (!sub_string)
		return (0);
	cnt = 0;
	while (start + cnt < s_len)
	{
		sub_string[cnt] = s[start + cnt];
		cnt++;
	}
	sub_string[cnt] = 0;
	free(s);
	return (sub_string);
}
