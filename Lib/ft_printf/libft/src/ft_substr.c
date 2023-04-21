/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 18:34:01 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/11/07 17:39:08 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	str_len;

	if (start >= ft_strlen(s) || !*s || s[start] == '\0')
	{
		sub_str = ft_strdup("");
		return (sub_str);
	}
	if (start + len > ft_strlen(s))
		str_len = ft_strlen(s) - start;
	else
		str_len = len;
	sub_str = malloc(sizeof(char) * (str_len + 1));
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, (s + start), str_len + 1);
	return (sub_str);
}
