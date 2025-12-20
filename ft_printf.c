/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:04:54 by yafakihi          #+#    #+#             */
/*   Updated: 2025/12/20 15:17:57 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
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

	va_start(ptr, format);
	i = 0;
	if (format == NULL)
		return (0);
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += printformat(format[i], ptr);
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

// int main() {
//     int x = 42;

//     ft_printf("=== Test 1: All conversions ===\n");
//     ft_printf("char: %c\n", 'A');
//     ft_printf("string: %s\n", "Hello");
//     ft_printf("pointer: %p\n", &x);
//     ft_printf("decimal: %d\n", -42);
//     ft_printf("integer: %i\n", 123);
//     ft_printf("unsigned: %u\n", 4294967295u);
//     ft_printf("hex lower: %x\n", 255);
//     ft_printf("hex upper: %X\n", 255);
//     ft_printf("percent: %%\n");

//     ft_printf("\n=== Test 2: Multiple variables ===\n");
//     ft_printf("Mix: %c %s %d %x %p\n", 'Z', "test", 42, 255, &x);

//     ft_printf("\n=== Test 3: Five variables ===\n");
//     ft_printf("v1=%d, v2=%d, v3=%d, v4=%d, v5=%d\n", 10, 20, 30, 40, 50);

//     ft_printf("\n=== Test 4: Edge cases ===\n");
//     ft_printf("NULL string: %s\n", NULL);
//     ft_printf("Zero: %d\n", 0);
//     ft_printf("Negative: %d\n", -2147483648);

//     return (0);
// }