/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utilities.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 19:38:21 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/11/17 19:38:21 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list args)
{
	int	param;

	param = va_arg(args, int);
	ft_putchar_fd(param, 1);
	return (1);
}

int	print_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_pointer(va_list args)
{
	int		x;
	char	*hexa;

	x = 0;
	hexa = "0123456789abcdef";
	ft_putstr_fd("0x", 1);
	x += ft_itoa_base((unsigned long)va_arg(args, void *), hexa) + 2;
	return (x);
}

int	print_hexa(va_list args)
{
	char	*hexa;
	int		x;

	x = 0;
	hexa = "0123456789abcdef";
	x += ft_itoa_base((unsigned int)va_arg(args, int), hexa);
	return (x);
}

int	print_hexa_upper(va_list args)
{
	char	*hexa;
	int		x;

	x = 0;
	hexa = "0123456789ABCDEF";
	x += ft_itoa_base((unsigned int)va_arg(args, int), hexa);
	return (x);
}
