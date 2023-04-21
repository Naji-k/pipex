/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 22:05:44 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/10/26 22:23:16 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len_dst = ft_strlen(dst);
	if (len_dst >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (dst[i])
		i++;
	while (j < dstsize - len_dst - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(src) + len_dst);
}
