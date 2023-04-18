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

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

//parsing
char	*get_env_path(char **envp);
char	*cmd_path(char *argv, char **envp);
void	put_error(char *msg);
void	free_all(char **str);
int		open_file(char *argv, int in_out);

//Bonus
void	multi_cmds_process(char **argv, char **envp, int cmd);
void	last_cmd(char *argv, char **envp);
void	parsing_input(int argc, char **argv, char **envp);
void	multi_pipex(int argc, char **argv, char **envp, int i);

#endif