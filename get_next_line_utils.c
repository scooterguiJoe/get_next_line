/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:55:03 by guvascon          #+#    #+#             */
/*   Updated: 2025/01/09 15:38:10 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i + s[i] == '\0');
}

/* char	*ft_strjoin(char *str, char *buffer)
{
	int			i;
	int			j;
	char		*s1;

	i = 0;
	j = 0;
	//if (!str && !buffer)
	//	return (NULL);
	s1 = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buffer) + 1));
	if (!s1)
		return (free(s1), NULL);
	while (str && str[i])
	{
		s1[i] = str[i];
		i++;
	}
	while (buffer[j])
	{
		s1[i + j] = buffer[j];
		// if (buffer[j] == '\n')
		// 	break ;
		j++;
	}
	if(buffer[j] == '\n')
		s1[i + j++] = '\n';
	s1[i + j] = '\0';
	return (free(str), s1);
} */

char	*ft_strjoin(char *str, char *buffer)
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
	//free(str);
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