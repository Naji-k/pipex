/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 19:23:59 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/04/20 19:23:59 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	put_error(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_all(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	open_file(char *argv, int in_out)
{
	int	file;

	if (in_out == 1)
	{
		file = open(argv, O_RDONLY, 0644);
		if (file < 0)
			put_error(NULL);
	}
	else
	{
		file = open(argv, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (file < 0)
			perror(NULL);
	}
	return (file);
}
