/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_path.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 13:38:26 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/04/12 13:38:26 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*cmd_path(char *argv, char **envp)
{
	int		i;
	char	*cmd;
	char	**cmd_arg;
	char	**my_paths;
	char	*path_from_env;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (!(envp[i]))
		exit(127);
	// printf("env=%s\n",envp[i]);
	path_from_env = envp[i];
	if (!path_from_env)
	{
		perror("");
		exit(127);
	}
	my_paths = ft_split(path_from_env, ':');
	i = -1;
	while (my_paths[++i])
	{
		my_paths[i] = ftp_strjoin(my_paths[i], "/");
		cmd_arg = ft_split(argv, ' ');
		cmd = ftp_strjoin(my_paths[i], cmd_arg[0]);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		free(cmd);
	}
	free(my_paths);
	perror("");
	exit(127);
	return (NULL);
}
void	put_error(void)
{
	perror("");
	exit(EXIT_FAILURE);
}
void	list_of_args(int argc, char **argv, t_list *list)
{
	t_list	*new;
	int		i;

	i = 2;
	while (i <= argc - 1)
	{
		new = ft_lstnew(argv[i]);
		ft_lstadd_back(&list, new);
		i++;
	}
}
bool	first_cmd(char *cmd_arg, char **argv)
{
	int	i;

	i = ft_strlen(cmd_arg);
	return (ft_strncmp(cmd_arg, argv[2], i));
}
bool	last_cmd(int argc, char *cmd_arg, char **argv)
{
	int	i;

	i = ft_strlen(cmd_arg);
	return (ft_strncmp(cmd_arg, argv[argc - 1], i));
}
void	open_pipes(int pipes[][2], int nCmnds)
{
	int	i;

	i = 0;
	while (i < nCmnds)
	{
		if (pipe(pipes[i]) == -1)
		{
			perror("pipe\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	close_pipes_exc(int pipes[][2], int process, int nCmnd)
{
	int	j;

	j = 0;
	while (j < nCmnd)
	{
		if (j != process)
			close(pipes[j][0]);
		if ((process + 1) != j)
			close(pipes[j][1]);
		j++;
	}
}

void	close_allpipes(int pipes[][2], int nCmnd)
{
	int j = 0;
	while (j < nCmnd)
	{
		close(pipes[j][0]);
		close(pipes[j][1]);
		j++;
	}
}