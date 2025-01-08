/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:55:10 by guvascon          #+#    #+#             */
/*   Updated: 2025/01/08 17:06:24 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *str, char const *buffer);
int		check_newline(char *str);
char	*get_next_line(int fd);

#endif