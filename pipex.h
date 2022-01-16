/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:24:58 by abernita          #+#    #+#             */
/*   Updated: 2022/01/10 15:25:01 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int     len_ch(char *str, char ch);
char    **ft_split(char *str, char del);
char    *str_ndup(char *str, unsigned int n);
char    *make_command(char *path, char *bin);
int     strnstr(char *str1, char *str2, int n);
void check_fork_for_error(pid_t parent);
void display_error(char* error_type, int error_close_parameter);

#endif