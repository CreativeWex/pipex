/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:30:33 by abernita          #+#    #+#             */
/*   Updated: 2022/01/11 15:30:39 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int openfile(char *file, int mode)
{
	if (mode == 0)
	{
		if (access(file, F_OK))
		{
			write(2, "File not found\n", 15);
			return (0);
		}
		return (open(file, O_RDONLY));
	}
	else
		return (open(file, O_CREAT | O_WRONLY | O_TRUNC,
		             S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
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
	while (path && len_ch(path, ':') > -1)
	{
		dir = str_ndup(path, len_ch(path, ':'));
		full = make_command(dir, cmd);
		free(dir);
		if (access(full, F_OK) == 0)
			return (full);
		free(full);
		path += len_ch(path, ':') + 1;
	}
	return (cmd);
}

void    child_process(char *cmd, char **env)
{
	char    **args;
	char    *path;

	args = ft_split(cmd, ' ');
	if (len_ch(args[0], ':') > -1)
		path = args[0];
	else
		path = full_path(args[0], env);
	execve(path, args, env);
	write(2, "Command not found\n", 19);
	exit(127);
}

void    parent_process(char *cmd, char **env, int f1)
{
	pid_t parent;
	int end[2];

	pipe(end);
	parent = fork();
	if (parent)
	{
		close(end[1]);
		dup2(end[0], 0);
	}
	else
	{
		close(end[0]);
		dup2(end[1], 1);
		if (f1 == 0)
			exit(1);
		else
			child_process(cmd, env);
	}
}

int main(int ac, char **av, char **env)
{
	int f1;
	int f2;
	int i;

	i = 3;
	if (ac >= 5)
	{
		f1 = openfile(av[1], 0);
		f2 = openfile(av[ac - 1], 1);
		dup2(f1, 0);
		dup2(f2, 1);
		parent_process(av[2], env, f1);
		while (i < ac - 2)
			parent_process(av[i++], env, 1);
		child_process(av[i], env);
//     wait();
	}
	else
		write(2, "Need 4 arguments\n", 18);
	return (1);
}