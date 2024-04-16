/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakonate <dakonate@student.24quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:44:19 by dakonate          #+#    #+#             */
/*   Updated: 2024/04/16 11:26:05 by dakonate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str, char *buf)
{
	char	*temp;

	temp = ft_strjoin(str, buf);
	free(str);
	return (temp);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	result = (char *)malloc((i + j + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == (char)c)
		return (str);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	char	*str;
	size_t	i;

	total_size = count * size;
	str = (char *)malloc(total_size);
	if (!str)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
