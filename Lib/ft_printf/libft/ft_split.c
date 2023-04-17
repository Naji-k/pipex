/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 18:14:50 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/11/07 19:28:56 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_counter(char const *s, char c)
{
	size_t	i;
	int		words;

	i = 0;
	words = 1;
	if (s[0] == c || s[0] == '\0')
		words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			words++;
		i++;
	}
	return (words);
}

static char	**free_all(char **split_str, int j)
{
	while (j >= 0)
	{
		free(split_str[j]);
		j--;
	}
	free(split_str);
	return (NULL);
}

static int	word_len(char const *s, int c, int i)
{
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static int	skip_del(char const *s, int c, int i)
{
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	end_i;
	int		words;
	size_t	start_i;
	char	**split_str;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	words = words_counter(s, c);
	split_str = malloc((words + 1) * sizeof(char *));
	if (!split_str)
		return (NULL);
	start_i = skip_del(s, c, 0);
	while (j < words)
	{
		end_i = word_len(s, c, start_i);
		split_str[j] = ft_substr(s, start_i, (end_i - start_i));
		if (!split_str[j])
			return (free_all(split_str, j));
		j++;
		start_i = skip_del(s, c, end_i);
	}
	split_str[j] = NULL;
	return (split_str);
}
