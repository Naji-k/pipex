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

char	*get_env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (&envp[i][5]);
		i++;
	}
	return (NULL);
}

char	*cmd_path(char *argv, char **envp)
{
	int		i;
	char	*cmd;
	char	**cmd_arg;
	char	**my_paths;
	char	*path_from_env;

	if (*argv == '\0')
		return (NULL);
	path_from_env = get_env_path(envp);
	if (path_from_env == NULL)
		return (NULL);
	my_paths = ft_split(path_from_env, ':');
	cmd_arg = ft_split(argv, ' ');
	i = -1;
	while (my_paths[++i])
	{
		my_paths[i] = ftp_strjoin(my_paths[i], "/");
		cmd = ft_strjoin(my_paths[i], cmd_arg[0]);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		free(cmd);
	}
	free_all(cmd_arg);
	free_all(my_paths);
	return (NULL);
}

char	*check_current_dir(char *argv)
{
	if (access(argv, F_OK) == -1)
		put_error("command not found\n");
	return (argv);
}
