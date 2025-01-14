/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:55:03 by guvascon          #+#    #+#             */
/*   Updated: 2025/01/14 12:01:56 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	if (s && s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *buffer)
{
	int			i;
	int			j;
	char		*s1;

	i = 0;
	j = 0;
	s1 = malloc(ft_strlen(str) + ft_strlen(buffer) + 1);
	if (!s1)
		return (NULL);
	while (str && str[i])
	{
		s1[i] = str[i];
		i++;
	}
	while (buffer[j] && buffer[j] != '\n')
	{
		s1[i + j] = buffer[j];
		if (buffer[j] == '\n')
			break ;
		j++;
	}
	if (buffer[j] == '\n')
	{
		s1[i + j] = '\n';
		j++;
	}
	s1[i + j] = '\0';
	free(str);
	return (s1);
}

void	check_newline(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	while (str[j] != '\0')
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = '\0';
} 

// int main()
// {
// 	char *s;
	
// 	s = ft_strjoin("fe", "liz");
// 	printf("%d\n", ft_strlen(s));
//     printf("%s\n", s);
//     return 0;
// }
// int main()
// {
//     char str[] = "feijao\n batata.";
      
//     check_newline(str);
//     printf("%s\n", str);
    
//     return 0;
// }