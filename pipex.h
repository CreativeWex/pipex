
#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int     char_first_encounter(char *str, char ch);
char    *ft_str_ndup(char *str, unsigned int n);
char	**ft_split(char *s, char c);
char    *make_command(char *path, char *bin);
int     strnstr(char *str1, char *str2, int n);
void check_fork_for_error(pid_t parent);
void display_error(char* error_type, int error_close_parameter);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif