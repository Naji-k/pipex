/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:38:55 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/10/11 20:59:18 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	if (*s == 0)
		return (0);
	return (1 + ft_strlen(s + 1));
}
