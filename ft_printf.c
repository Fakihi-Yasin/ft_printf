/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:04:54 by yafakihi          #+#    #+#             */
/*   Updated: 2025/12/16 21:12:30 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printformat(char specifier, va_list ptr)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ptr, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ptr, char *));
	else if(specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(ptr, int));
	else if(specifier == 'x')
		count == ft_puthex(va_arg(ptr, unsigned int));
	else if(specifier == 'u')
		count == ft_putptr(va_arg(ptr, int));
	else if(specifier == '%')
		count == ft_putchar('%');
	return count;
	

}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		count;
	int     i;
	i = 0;

	if (format == NULL)
		return (0);
	count = 0;
  	while (format[i])
	{
		if (format[i] == '%' && !format[i + 1])
		printformat(format[i+1] );
	
	}
	va_end(ptr);
	return (count);
}