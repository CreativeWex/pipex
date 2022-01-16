#include "pipex.h"

//126 - command cant be executed
//127 - A utility to be executed was not found.

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	write(2, s, ft_strlen(s));
}

void display_error(char* error_type, int error_close_parameter)
{

    ft_putstr("Error: ");
    ft_putstr(error_type);
    ft_putstr("\n");
    exit(error_close_parameter);
}

void check_fork_for_error(pid_t parent)
{
    if (parent == -1)
        display_error("Fork error", 126);
}