/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/10 14:55:38 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/04/10 14:55:38 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

//parsing
char	**parsing_path(char **envp);
char	*cmd_path(char *argv, char **envp);
void	put_error(void);
//pipes
void	open_pipes(int pipes[][2], int nCmnds);

bool	first_cmd(char *cmd_arg, char **argv);
bool	last_cmd(int argc, char *cmd_arg, char **argv);
void	fst_child_process(int fd[], char *cmd, char *arg);
void	list_of_args(int argc, char **argv, t_list *list);

//debug
void	print_lst(t_list *lst);