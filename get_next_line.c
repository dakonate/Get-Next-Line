/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakonate <dakonate@student.24quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:21:16 by dakonate          #+#    #+#             */
/*   Updated: 2024/04/16 15:49:18 by dakonate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*set_line(char *str)
{
	int		i;
	char	*lig_chaine;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	lig_chaine = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		lig_chaine[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
	{
		lig_chaine[i++] = '\n';
	}
	return (lig_chaine);
}

char	*rest_of_lines(char *str)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	s = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (str[i])
	{
		s[j] = str[i];
		j++;
		i++;
	}
	s[j] = 0;
	free(str);
	return (s);
}

char	*read_line(int fd, char *str)
{
	char	*buffer;
	int		i;

	if (!str)
		str = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = 0;
		str = ft_free(str, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(str);
		str = NULL;
		return (0);
	}
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	line = set_line(str);
	str = rest_of_lines(str);
	return (line);
}

// int main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("test.txt", O_RDONLY);

// 	if (fd < 0)
// 	{
// 		perror("Error opening file");
// 		return EXIT_FAILURE;
// 	}

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}

// 	close(fd);

// 	return EXIT_SUCCESS;
// }