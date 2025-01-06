/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:55:03 by guvascon          #+#    #+#             */
/*   Updated: 2025/01/06 15:03:05 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char str)
{
    size_t i;

    i = 0;
    if (!str)
        return (0);
    while (str[i] && str[i] != '\n')
        i++;
    return(i + (s[i] == '\n'));
}

char	*ft_strjoin(char const *s1, char const *buffer)
{
	int			i;
	int			j;
	char		*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(buffer)+ 1));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (buffer[j])
	{
		str[i + j] = buffer[j];
        if (buffer[j++] == '\n')
            break;
	}
	str[i + j] = '\0';
    free(s1);
	return (str);
}

void	check_newline(char *str)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		i++;
	while (str[j] != '\0')
		str[i] = str[j];
		i++;
		j++;
}