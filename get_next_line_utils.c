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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			j;
	char		*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)+ 1));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
        if (s2[j++] == '\n')
            break;
	}
	str[i + j] = '\0';
    free(s1);
	return (str);
}