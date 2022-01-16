/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:40:35 by abernita          #+#    #+#             */
/*   Updated: 2022/01/10 20:40:38 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int     len_ch(char *str, char ch)
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

	buff = malloc(sizeof(char) * (len_ch(path, 0) + len_ch(bin, 0) + 2));
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

char    *str_ndup(char *str, unsigned int n)
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

char    **ft_split(char *str, char del)
{
	char    **tab;
	int     count;
	int     i;
	int     j;

	count = 0;
	j = 0;
	while (str[j])
	{
		if (str[j++] == del)
			count++;
	}
	tab = malloc(sizeof(char *) * (count + 2));
	if (tab == NULL)
		return (NULL);
	tab[count + 1] = NULL;
	i = 0;
	while (i < count + 1)
	{
		j = 0;
		while (str[j] && str[j] != del)
			j++;
		tab[i++] = str_ndup(str, j);
		str = str + j +1;
	}
	return (tab);
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
