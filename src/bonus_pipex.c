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
		put_error("pipe\n");
	pid = fork();
	if (pid < 0)
		put_error("fork\n");
	if (pid == 0)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			put_error("dup2 fail\n");
		cmdpath = cmd_path(argv[cmd], envp);
		if (!cmdpath)
			cmdpath = check_current_dir(argv[cmd]);
		cmdarg = ft_split(argv[cmd], ' ');
		execve(cmdpath, cmdarg, NULL);
		put_error("execve fail\n");
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
			cmdpath = check_current_dir(argv);
		cmdarg = ft_split(argv, ' ');
		execve(cmdpath, cmdarg, NULL);
		put_error("execve fail\n");
	}
	waitpid(pid, NULL, 0);
}

void	parsing_input(int argc, char **argv, char **envp)
{
	char	s[10000];
	int		n;
	int		len_limiter;
	int		i;
	int		file1;

	n = 1;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		len_limiter = ft_strlen(argv[2]);
		file1 = open_file("here_doc", 2);
		while (n > 0 && ft_strncmp(s, argv[2], len_limiter) != 0)
		{
			n = read(1, &s, 10000);
			if (ft_strncmp(s, argv[2], len_limiter) != 0)
				write(file1, &s, n);
		}
		close(file1);
		i = 3;
	}
	else
		i = 2;
	multi_pipex(argc, argv, envp, i);
}

void	multi_pipex(int argc, char **argv, char **envp, int i)
{
	int	file1;
	int	file2;

	file1 = open(argv[1], O_RDONLY, 0644);
	if (file1 != -1)
	{
		if (dup2(file1, STDIN_FILENO) == -1)
			put_error("dup2 fail\n");
	}
	else
		perror(NULL);
	file2 = open_file(argv[argc - 1], 2);
	while (i < argc - 2)
		multi_cmds_process(argv, envp, i++);
	if (dup2(file2, STDOUT_FILENO) == -1)
		put_error("dup2 fail\n");
	close(file1);
	close(file2);
	last_cmd(argv[argc - 2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc > 4)
	{
		if (*argv[1] == '\0' || *argv[argc - 1] == '\0')
			exit(EXIT_FAILURE);
		parsing_input(argc, argv, envp);
	}
	else
	{
		ft_putstr_fd("invalid inputs\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
