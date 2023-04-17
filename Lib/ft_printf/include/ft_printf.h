/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 00:16:06 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/11/08 00:16:06 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef int	(*t_print_fns_list)(va_list args);
int			ft_printf(const char *holder, ...);
int			get_index(const char *str, char const c);
int			ft_itoa_base(unsigned long num, char *base_table);
int			nbr_len(unsigned long num, int base_system);
int			print_char(va_list args);
int			print_string(va_list args);
int			print_dec(va_list args);
int			print_pointer(va_list args);
int			print_hexa(va_list args);
int			print_hexa_upper(va_list args);
int			print_unsigned(va_list args);
int			print_percentage(void);
int			check_print_table(const char *holder, va_list args);

#endif