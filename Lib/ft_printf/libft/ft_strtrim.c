/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 23:29:11 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/10/24 18:01:50 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s1)
		return (ft_strdup(""));
	i = 0;
	len = ft_strlen(s1);
	while (ft_strrchr(set, s1[i]) != 0 && i < len)
		i++;
	while (ft_strrchr(set, s1[len]) != 0 && len > i)
		len--;
	str = ft_substr(s1, i, (len - i + 1));
	return (str);
}
