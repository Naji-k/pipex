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

void	check_leaks(void)
{
	system("leaks -q pipex");
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	file1;
	int	file2;

	if (argc > 4)
	{
		i = 2;
		file1 = open(argv[1], O_RDONLY, 0644);
		file2 = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (file1 < 0 || file2 < 0)
			perror("");
		dup2(file1, STDIN_FILENO);
		while (i < argc - 2)
			multi_cmds_process(argv, envp, i++);
		dup2(file2, STDOUT_FILENO);
		last_cmd(argv[argc - 2], envp);
	}
	else
	{
		ft_putstr_fd("invalid inputs\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
