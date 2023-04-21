/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 19:24:46 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/11/07 19:28:37 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*csrc;
	char		*cdest;

	csrc = src;
	cdest = dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (cdest > csrc)
	{
		while (n--)
			cdest[n] = csrc[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
