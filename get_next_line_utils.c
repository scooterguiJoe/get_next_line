/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:55:03 by guvascon          #+#    #+#             */
/*   Updated: 2025/01/08 17:07:20 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i + (s[i] == '\n'));
}

char	*ft_strjoin(char const *str, char const *buffer)
{
	int			i;
	int			j;
	char		*s1;

	i = 0;
	j = 0;
	if (!str && !buffer)
		return (NULL);
	s1 = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buffer) + 1));
	if (!s1)
		return (NULL);
	while (str && str[i])
	{
		s1[i] = str[i];
		i++;
	}
	while (buffer[j])
	{
		s1[i + j] = buffer[j];
		if (buffer[j] == '\n')
			break ;
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

int	check_newline(char *str)
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
	return (0);
}


// int	check_newline(char *str)
// {
// 	int	i;
// 	int	j;
	
// 	i = 0;
// 	while (str[i] != '\n' && str[i] != '\0')
// 		i++;
// 	if (str[i] == '\n')
// 	{
// 		str[i] = '\0';
// 		return (1);
// 	}
// 	return (0);
// }


// int main()
// {
// 	char *s;
	
// 	s = ft_strjoin("fe", "liz");
// 	printf("%zu\n", ft_strlen(s));
//     printf("%s\n", s);
//     return 0;
// }
// // // int main()
// {
//     char str[] = "arroz\n feijao\n batata.";
      
//     check_newline(str);
//     printf("%s\n", str);
    
//     return 0;
// }