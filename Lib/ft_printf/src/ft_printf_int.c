/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_int.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 22:58:38 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/11/18 22:58:38 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_dec(va_list args)
{
	char	*base_10;
	int		x;
	int		num;

	num = va_arg(args, int);
	base_10 = "0123456789";
	x = 0;
	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
		x++;
	}
	x += ft_itoa_base((unsigned int)num, base_10);
	return (x);
}

int	print_unsigned(va_list args)
{
	char	*base_10;
	int		x;

	x = 0;
	base_10 = "0123456789";
	x += ft_itoa_base(va_arg(args, unsigned int), base_10);
	return (x);
}

int	print_percentage(void)
{
	int	x;

	x = 0;
	write(1, "%", 1);
	x++;
	return (x);
}
