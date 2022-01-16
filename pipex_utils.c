

#include "pipex.h"

int     char_first_encounter(char *str, char ch)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ch)
		i++;
	if (str[i] == ch)
		return (i);
	return (-1);
}

char    *make_command(char *path, char *bin)
{
	int     i;
	int     j;
	char    *buff;

	buff = malloc(sizeof(char) * (char_first_encounter(path, 0) + char_first_encounter(bin, 0) + 2));
	if (buff == NULL)
		return (NULL);	
	i = 0;
	j = 0;
	while (path[j])
		buff[i++] = path[j++];
	buff[i++] = '/';
	j = 0;
	while (bin[j])
		buff[i++] = bin[j++];
	buff[i] = '\0';
	return (buff);
}

char    *ft_str_ndup(char *str, unsigned int n)
{
	unsigned int    i;
	char            *buff;

	i = 0;
	buff = malloc(sizeof(char) * (n + 1));
	if (buff == NULL)
		return (NULL);
	while (i < n)
		buff[i++] = *str++;
	buff[n] = '\0';
	return (buff);
}

// Ищет первое вхождение n символов строки str2 в str1
int     strnstr(char *str1, char *str2, int n)
{
	while (*str1 && *str2 && *str1 == *str2 && --n > 0)
	{
		str1++;
		str2++;
	}
	return (*str2 - *str1);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		length;

	length = ft_strlen(s1);
	p = (char *) malloc(length + 1);
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s1, length);
	p[length] = '\0';
	return (p);
}