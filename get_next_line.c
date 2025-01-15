/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:22:30 by guvascon          #+#    #+#             */
/*   Updated: 2025/01/15 15:21:45 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	line = NULL;
	while (buff[0] || read(fd, buff, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buff);
		//printf("line 1= %s\n", line);
		if (!line)
			return (NULL);
		//printf("line 2= %s\n", line);
		check_newline(buff);
		//printf("line 3= %s\n", line);
		if (line[ft_strlen(line) - 1] == '\n')
			return (line);
		
	}
	return (line);
}

//  int main()
// {
// 	int fd = open("teste.txt", O_RDONLY);
// 	char *str;
// 	str = get_next_line(fd);
// 	printf("%s\n", str);
// 	str = get_next_line(fd);
// 	printf("%s\n", str);
// 	free (str);
// 	close(fd);
// 	return (0);
// } 
// int main()
// {
// 	int i = 0;
	
// 	int fd = open("teste.txt", O_RDONLY);
// 	while (i < 3)
// 	{
// 		printf("%s\n", get_next_line(fd));
// 		i++;
// 	}
// 	return 0;
// }