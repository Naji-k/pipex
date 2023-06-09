/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/10 14:02:01 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/04/10 14:02:01 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(int *fd, char **argv, char **envp)
{
	int		file1;
	char	*cmdpath;
	char	**cmd_arg;

	file1 = open_file(argv[1], 1);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		put_error("dup2 fail\n");
	if (dup2(file1, STDIN_FILENO) == -1)
		put_error("dup2 fail\n");
	close(fd[0]);
	cmdpath = cmd_path(argv[2], envp);
	if (!cmdpath)
		cmdpath = check_current_dir(argv[2]);
	cmd_arg = ft_split(argv[2], ' ');
	execve(cmdpath, cmd_arg, NULL);
	put_error("execve fail\n");
}

void	parent(int *fd, char **argv, char **envp)
{
	int		file2;
	char	*cmdpath;
	char	**cmd_arg;

	file2 = open_file(argv[4], 2);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		put_error("dup2 fail\n");
	if (dup2(file2, STDOUT_FILENO) == -1)
		put_error("dup2 fail\n");
	close(fd[1]);
	cmdpath = cmd_path(argv[3], envp);
	if (!cmdpath)
		cmdpath = check_current_dir(argv[3]);
	cmd_arg = ft_split(argv[3], ' ');
	execve(cmdpath, cmd_arg, NULL);
	put_error("execve fail\n");
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("invalid parameter", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (*argv[1] == '\0' || *argv[4] == '\0')
		return (1);
	if (pipe(fd) == -1)
		put_error("pipe\n");
	pid = fork();
	if (pid < 0)
		put_error("pipe\n");
	if (pid == 0)
		first_child(fd, argv, envp);
	else
	{
		waitpid(pid, NULL, 0);
		parent(fd, argv, envp);
	}
	return (0);
}
