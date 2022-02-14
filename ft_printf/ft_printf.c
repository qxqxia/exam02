/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:20:43 by qxia              #+#    #+#             */
/*   Updated: 2022/02/14 12:01:05 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int ft_print_d(int nbr)
{
	char *int_string = "0123456789";
	int ret = 0;

	if (nbr == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		nbr *= -1;
		ret += write(1, "-", 1);
	}
	if (nbr / 10 != 0)
		ret += ft_print_d(nbr / 10);
	ret += write(1, &int_string[nbr % 10], 1);
	return (ret);
}

int ft_print_x(unsigned int nbr)
{
	char *hex_string = "0123456789abcdef";
	int ret = 0;

	if (nbr / 16 != 0)
		ret += ft_print_x(nbr / 16);
	ret += write (1, &hex_string[nbr % 16], 1);
	return (ret);
}

int ft_print_s(char *str)
{
	int ret = 0;

	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		ret += write(1, str, 1);
		str++;
	}
	return (ret);
}

int ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int ret = 0;

	va_start(ap, fmt);
	while(*fmt)
	{
		if (fmt[0] == '%')
		{
			fmt++;
			if (fmt[0] == '%')
				ret += write(1, "%", 1);
			else if (fmt[0] == 's')
				ret += ft_print_s((char *)va_arg(ap, void*));
			else if (fmt[0] == 'd')
				ret += ft_print_d(va_arg(ap, int));
			else if (fmt[0] == 'x')
				ret += ft_print_x(va_arg(ap, unsigned int));
			else
				ret += write(1, (fmt - 1), 2);
		}
		else
			ret += write (1, fmt, 1);
		fmt++;
	}
	va_end(ap);
	return (ret);
}

//int main()
{
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);	
	return (0);
}//
