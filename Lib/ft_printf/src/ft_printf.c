/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 15:35:33 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/11/08 15:35:33 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *holder, ...)
{
	int		p_counter;
	va_list	args;

	p_counter = 0;
	va_start(args, holder);
	while (*holder != '\0')
	{
		if (*holder == '%')
		{
			holder++;
			if (*holder != '\0')
				p_counter += check_print_table(holder, args);
			else
				break ;
		}
		else if (*holder != '%' && *holder != '\0')
		{
			p_counter++;
			write(1, holder, 1);
		}
		holder++;
	}
	va_end(args);
	return (p_counter);
}

int	check_print_table(const char *holder, va_list args)
{
	static const t_print_fns_list	fn_list[256] = {
	['c'] = print_char,
	['s'] = print_string,
	['d'] = print_dec,
	['i'] = print_dec,
	['p'] = print_pointer,
	['x'] = print_hexa,
	['X'] = print_hexa_upper,
	['u'] = print_unsigned,
	};
	int								x;

	x = 0;
	if (fn_list[(int)*holder])
		x += fn_list[(int)*holder](args);
	else if (*holder == '%')
		x += print_percentage();
	else if (*holder != '%' && *holder != '\0')
	{
		x++;
		write(1, holder, 1);
	}
	return (x);
}
/* #include<stdio.h>
int	main(void)
{
	// char s = 's';
	// ft_printf("%s %s + 256 ", "1", "2");
	// printf("\n%s %s ", "1", "2");
	// printf("\n %c %c %c ", '0', 0, '1');
	// printf("\n %c ", '0' + 256);
	// printf("\t%d", printf("a \0ba"));
	// printf("\n----me----\n");
	printf("ori=%d\n", printf("%%% \\0ba\n"));
	printf("me=%d\n", ft_printf("%%% \\0ba\n"));
	// printf("\t%d", ft_printf("%%%randomdata"));
} */