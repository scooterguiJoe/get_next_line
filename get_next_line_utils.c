/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:55:03 by guvascon          #+#    #+#             */
/*   Updated: 2025/01/07 17:56:59 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i] && str[i] != '\n')
// 		i++;
// 	return(i + (str[i] == '\n'));
// }

// char	*ft_strjoin(char const *s1, char const *buffer)
// {
// 	int			i;
// 	int			j;
// 	char		*str;

// 	i = 0;
// 	j = 0;
// 	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(buffer)+ 1));
// 	if (!str)
// 		return (0);
// 	while (s1[i])
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	while (buffer[j])
// 	{
// 		str[i + j] = buffer[j];
// 		if (buffer[j++] == '\n')
// 			break;
// 	}
// 	str[i + j] = '\0';
// 	//free(s1);
// 	return (str);
// }

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

// int main ()
// {
// 	char *c;

// 	c = ft_strjoin("Fe", "liz");
// 	printf ("%s\n%d\n", c, ft_strlen(c));
// 	//printf ("%zu\n", ft_strlen(c));
// 	return (0);
// }

// int main()
// {
//     char str[100] = "teste\ncom nova linha.";
    
//     check_newline(str);
//     printf("Depois: %s\n", str);
    
//     return 0;
// }
int main()
{
    char str[] = "Exemplo de texto\ncom nova linha.";
    
    
    check_newline(str);
    printf("%s\n", str);
    
    return 0;
}