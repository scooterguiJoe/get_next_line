/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:16:23 by guvascon          #+#    #+#             */
/*   Updated: 2025/01/14 12:20:13 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	line = NULL;
	while (buff[fd][0] || read(fd, buff[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buff[fd]);
		//printf("line 1= %s\n", line);
		if (!line)
			return (NULL);
		//printf("line 2= %s\n", line);
		check_newline(buff[fd]);
		//printf("line 3= %s\n", line);
		if (line[ft_strlen(line) - 1] == '\n')
			return (line);
		
	}
	return (line);
}
int main()
{
	int i = 0;
	
	int fd = open("teste.txt", O_RDONLY);
	while (i < 3)
	{
		printf("%s\n", get_next_line(fd));
		i++;
	}
	return 0;
}