/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 00:34:21 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/10/26 22:23:02 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if ((*str1 == 0 || *str2 == 0) && n != 0)
		return (*str1 - *str2);
	while (*str1 == *str2 && i < n)
	{
		if (*str1 == 0 || *str2 == 0)
			return (*str1 - *str2);
		str1++;
		str2++;
		i++;
	}
	while (i < n)
		return (*str1 - *str2);
	return (0);
}
