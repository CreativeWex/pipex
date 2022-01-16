

#include "pipex.h"

int openfile(char *file, int mode)
{
    if (mode == 0)
    {
        if (access(file, F_OK))
            display_error("File not found", 127);

		if (open(file, O_RDONLY) == -1)
			display_error("Can not open file", 127);

		return (open(file, O_RDONLY));
    }
    return (open(file, O_CREAT | O_WRONLY | O_TRUNC, 0777));
}

char    *full_path(char *cmd, char **env)
{
	int     i;
	char    *path;
	char    *dir;
	char    *full;

	i = 0;
	while (env[i] && strnstr(env[i], "PATH=", 5))
		i++;

	if (!env[i])
		return (cmd);

	path = env[i] + 5;
	while (path && char_first_encounter(path, ':') > -1)
	{
		dir = ft_str_ndup(path, char_first_encounter(path, ':'));
		full = make_command(dir, cmd);
		free(dir);
		if (access(full, F_OK) == 0)
			return (full);
		free(full);
		path += char_first_encounter(path, ':') + 1;
	}
	return (cmd);
}

void    child_process(char *cmd, char **env)
{
	char    **args;
	char    *path;

	args = ft_split(cmd, ' ');
	if (char_first_encounter(args[0], '/') > -1)
		path = args[0];
	else
		path = full_path(args[0], env);
	execve(path, args, env);
	display_error("Command not found", 127);
}

void    parent_process(char *cmd, char **env, int f1)//!!!!!!!!!!!!!!!!!!
{
	pid_t parent;
	int end[2];

	if (pipe(end)== -1)
		display_error("Pipe error", 126);

	parent = fork();
	check_fork_for_error(parent);
	if (parent)
	{
		if (close(end[1]) == -1 || dup2(end[0], 0) == -1)
			display_error("Parent process error", 126);
	}
	else
	{
		if (close(end[0]) == -1 || dup2(end[1], 1) == -1 || f1 == 0)
			display_error("Child process error", 126);
		child_process(cmd, env);
	}
}

int main(int ac, char **av, char **env)
{
    int f1;
    int f2;

    if (ac == 5)
    {
		f1 = openfile(av[1], 0);
		f2 = openfile(av[4], 1);
		if (dup2(f1, 0) == -1 || dup2(f2, 1) == -1)
			display_error("Dup2 error", 126);
			
		parent_process(av[2], env, f1);
		child_process(av[3], env);
	}
	else
	    write(2, "Need 4 arguments\n", 18);
    return (1);
}