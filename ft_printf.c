/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:04:54 by yafakihi          #+#    #+#             */
/*   Updated: 2025/12/25 14:12:13 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	printformat(char specifier, va_list ptr)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ptr, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ptr, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(ptr, int));
	else if (specifier == 'x')
		count += ft_puthex(va_arg(ptr, unsigned int), 0);
	else if (specifier == 'X')
		count += ft_puthex(va_arg(ptr, unsigned int), 1);
	else if (specifier == 'u')
		count += ft_putnbr_unsigned(va_arg(ptr, unsigned int));
	else if (specifier == 'p')
		count += ft_putptr(va_arg(ptr, void *));
	else if (specifier == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		count;
	int		i;

	if (format == NULL)
		return (0);
	va_start(ptr, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += printformat(format[i + 1], ptr);
			i++;
		}
		else if (format[i] == '%' && !format[i + 1])
			break ;
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ptr);
	return (count);
}

// int	main()
// {
// 	char *p = "hello";
// 	ft_printf(p);
// }