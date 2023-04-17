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

/* 
	./pipex infile cmd1 cmd2 outfile
	./pipex infile "ls -l" "wc -l" outfile
	< infile cmd1 | cmd2 > outfile

	int execve(const char *path, char *const argv[], char *envp[]);

 */

void	first_child(int *fd, char **argv, char **envp)
{
	int		file1;
	char	*cmdpath;
	char	**cmd_arg;


	file1 = open(argv[1], O_RDONLY, 0644);
	if (file1 < 0)
		perror("");
	dup2(fd[1], STDOUT_FILENO);
	dup2(file1, STDIN_FILENO);
	close(fd[0]);
	cmdpath = cmd_path(argv[2], envp);
	cmd_arg = ft_split(argv[2], ' ');
	if (execve(cmdpath, cmd_arg, NULL) == -1)
		put_error();
}
void	parent(int *fd, char **argv, char **envp)
{
	int		file2;
	char	*cmdpath;
	char	**cmd_arg;

	file2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file2 < 0)
		put_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(fd[1]);
	cmdpath = cmd_path(argv[3], envp);
	// if (!cmdpath)
	// 	put_error();
	cmd_arg = ft_split(argv[3], ' ');
	if (execve(cmdpath, cmd_arg, NULL) == -1)
		put_error();
}
void check_leaks(void)
{
	system("leaks -q pipex");
}
int	main(int argc, char **argv, char **envp)
{
	int fd[2];
	pid_t pid;

	if (argc != 5)
	{
		ft_putstr_fd("invalid parameter", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (pipe(fd) == -1)
			put_error();
		pid = fork();
		if (pid < 0)
			put_error();
		if (pid == 0)
			first_child(fd, argv, envp);
		else
		{
			waitpid(pid, NULL, 0);
			parent(fd, argv, envp);
		}
	}
	return (0);
}