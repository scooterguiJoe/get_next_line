/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:22:30 by guvascon          #+#    #+#             */
/*   Updated: 2025/01/08 17:07:45 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[BUFFER_SIZE + 1];
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
	{
		while (buff[i])
			buff[i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (*buff || read(fd, buff, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buff);
		if (check_newline(buff) == '\0')
			break ;
	}
	return (line);
}

 int main()
{
	int fd = open("teste.txt", O_RDONLY);
	char *str;
	str = get_next_line(fd);
	printf("%s\n", str);
	str = get_next_line(fd);
	printf("%s\n", str);
	return (0);
} 