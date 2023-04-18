/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus_pipex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/14 22:51:38 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/04/14 22:51:38 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	multi_cmds_process(char **argv, char **envp, int cmd)
{
	char	*cmdpath;
	char	**cmdarg;
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		put_error();
	pid = fork();
	if (pid < 0)
		put_error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		cmdpath = cmd_path(argv[cmd], envp);
		if (!cmdpath)
			put_error();
		cmdarg = ft_split(argv[cmd], ' ');
		execve(cmdpath, cmdarg, NULL);
		put_error();
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
}

void	last_cmd(char *argv, char **envp)
{
	char	*cmdpath;
	char	**cmdarg;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		cmdpath = cmd_path(argv, envp);
		if (!cmdpath)
			put_error();
		cmdarg = ft_split(argv, ' ');
		execve(cmdpath, cmdarg, NULL);
		put_error();
	}
	waitpid(pid, NULL, 0);
	while (wait(NULL) != -1)
		;
}

void	parsing_input(int argc, char **argv, char **envp)
{
	char	s[10000];
	int		n;
	int		len_limiter;
	int		i;
	int		file1;
	int		file2;

	file1 = 0;
	n = 1;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		len_limiter = ft_strlen(argv[2]);
		while (n > 0 && ft_strncmp(s, argv[2], len_limiter) != 0)
			n = read(1, &s, 10000);
		i = 3;
		dup2(STDIN_FILENO, file1);
		close(file1);
	}
	else
	{
		i = 2;
		file1 = open_file(argv[1], 1);
	}
	dup2(file1, STDIN_FILENO);
	file2 = open_file(argv[argc - 1], 2);
	while (i < argc - 2)
		multi_cmds_process(argv, envp, i++);
	dup2(file2, STDOUT_FILENO);
	close(file1);
	close(file2);
	last_cmd(argv[argc - 2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc > 4)
	{
		parsing_input(argc, argv, envp);
	}
	else
	{
		ft_putstr_fd("invalid inputs\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
