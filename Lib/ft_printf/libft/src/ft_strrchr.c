/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 23:17:58 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/11/02 17:24:24 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		str_len;
	char	*res;

	res = "";
	str_len = ft_strlen(str);
	if (*str == '0')
		return (res);
	while (str_len >= 0)
	{
		if (str[str_len] == (char)c)
			return ((char *)str + str_len);
		str_len--;
	}
	return (NULL);
}
