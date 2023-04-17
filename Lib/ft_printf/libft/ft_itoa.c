/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 20:03:07 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/11/03 00:06:03 by NajiKanounj   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cal_int(int n)
{
	int	i;
	int	sign;

	sign = 0;
	i = 0;
	if (n <= 0)
		sign += 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i + sign);
}

void	recursive(char *str, int num, int index)
{
	if (num == 0)
		str[index] = '0';
	if (num > 9)
	{
		recursive(str, (num / 10), index - 1);
		recursive(str, (num % 10), (index));
	}
	else if (num <= 9)
	{
		str[index] = num + '0';
		num = num / 10;
	}
}

char	*ft_itoa(int n)
{
	int		str_len;
	int		num;
	char	*str;

	num = n;
	str_len = cal_int(n);
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(sizeof(char) * (str_len + 1));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		recursive(str, num, str_len - 1);
		str[0] = '-';
	}
	else
		recursive(str, num, str_len - 1);
	str[str_len] = '\0';
	return (str);
}
