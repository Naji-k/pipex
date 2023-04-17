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

void	child(int argc, char **argv, char **envp, int *fd, int cmd)
{
	char	*cmdpath;
	char	**cmdarg;
	int		file1;
	int		file2;

	file1 = open(argv[1], O_RDONLY, 0644);
	file2 = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file1 < 0)
		put_error();
	cmdpath = cmd_path(argv[cmd], envp);
	if (!cmdpath)
		put_error();
	cmdarg = ft_split(argv[cmd], ' ');
	if (cmd == 2)
	{
		dup2(file1, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
	}
	else
	{
		dup2(fd[2], STDIN_FILENO);
		dup2(fd[3], STDOUT_FILENO);
	}
	// close(fd[0]);
	execve(cmdpath, cmdarg, NULL);
}
void	parent(int argc, char **argv, char **envp, int *fd, int cmd)
{
	char	*cmdpath;
	char	**cmdarg;
	int		file2;

	cmdpath = cmd_path(argv[cmd], envp);
	cmdarg = ft_split(argv[cmd], ' ');
	file2 = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (!cmdpath)
		put_error();
	dup2(file2, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	// execve(cmdpath, cmdarg, NULL);
}
void	check_leaks(void)
{
	system("leaks -q pipex");
}
int	main(int argc, char **argv, char **envp)
{
	int fd[4];
	int i;
	pid_t pid;

	// atexit(check_leaks);
	if (argc > 4)
	{
		i = 2;
		if (pipe(fd) < 0)
			put_error();
		while (i < argc - 2)
		{
			pid = fork();
			if (pid < 0)
				put_error();
			if (pid == 0)
				child(argc, argv, envp, fd, i);
			waitpid(pid, NULL, 0);
			parent(argc, argv, envp, fd, ++i);
		}
	}
	else
	{
		ft_putstr_fd("invalid inputs\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
