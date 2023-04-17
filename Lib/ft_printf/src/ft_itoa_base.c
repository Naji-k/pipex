/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/09 20:30:35 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/11/09 20:30:35 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	converter(unsigned long num, char *base_table,
		unsigned int base_system)
{
	if (num >= base_system)
	{
		converter((num / base_system), base_table, base_system);
		converter((num % base_system), base_table, base_system);
	}
	if (num < base_system)
	{
		ft_putchar_fd(base_table[num], 1);
	}
	return (nbr_len(num, base_system));
}

int	ft_itoa_base(unsigned long num, char *base_table)
{
	unsigned int	base_system;
	int				x;

	x = 0;
	base_system = ft_strlen(base_table);
	x = converter(num, base_table, base_system);
	return (x);
}

int	nbr_len(unsigned long num, int base_system)
{
	int	i;

	i = 0;
	if (num <= 0)
		i++;
	while (num)
	{
		num = num / base_system;
		i++;
	}
	return (i);
}

/* int	main(void)
{
	char	*hexa_base;
	char	*base_10;

	hexa_base = "0123456789ABCDEF";
	base_10 = "0123456789";
	ft_itoa_base(-1, hexa_base);
	printf("\t%d", printf("\n%x", -1));
} */