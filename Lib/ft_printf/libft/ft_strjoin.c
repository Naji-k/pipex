/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 23:02:12 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/10/20 23:27:04 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_join;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_join = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str_join)
		return (NULL);
	ft_strlcpy(str_join, s1, s1_len + 1);
	ft_strlcat(str_join, s2, s1_len + s2_len + 1);
	return (str_join);
}
