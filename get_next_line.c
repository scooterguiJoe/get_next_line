/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:22:30 by guvascon          #+#    #+#             */
/*   Updated: 2025/01/09 15:38:22 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	char *str;
// 	static char buf[BUFFER_SIZE + 1];

// 	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
// 		return (NULL);
// 	str = NULL;
// 	while (buf[0] || read (fd, buf, BUFFER_SIZE) > 0)
// 	{
// 		str = ft_strjoin(buf, str);
// 		if (!str)
// 			return(NULL);
// 		check_newline(buf);
// 		if(str[ft_strlen(str) - 1] == '\n')
// 			return(str);
// 	}
// 	return (str);
// }
/* char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;

	str = 0;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	while (*buffer || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buffer);
		if (check_newline(buffer))
			break ;
	}
	return (str);
} */

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
// int main()
// {
// 	int i;
// 	int fd;

// 	i = 0;
// 	fd = open("teste.txt", O_RDONLY);
// 	printf("%s\n", get_next_line(fd));
	
// 	return (0);
// }