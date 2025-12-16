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
		count += ft_puthex(va_arg(ptr, unsigned int));
	else if(specifier == 'X')
		count += ft_puthex(va_arg(ptr, unsigned int));
	else if(specifier == 'u')
		count == ft_putnbr_unsigned(va_arg(ptr, unsigned int));
	else if(specifier == 'p')
		count += ft_putptr(va_arg(ptr, void *));
	else if(specifier == '%')
		count == ft_putchar('%');
	return count;
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	va_start(ptr, format);
	int		count;
	int     i;
	i = 0;

	if (format == NULL)
		return (0);
	count = 0;
  	while (format[i])
	{
		if (format[i] == '%' && format[i + 1]){
			i++;
			count += printformat(format[i], ptr);
		}
		else if(format[i] == '%' && !format[i + 1]){
			break;
		}
		else{
			count += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(ptr);
	return (count);
}


int main() {
    int x = 42;
    
    ft_printf("=== Test 1: All conversions ===\n");
    ft_printf("char: %c\n", 'A');
    ft_printf("string: %s\n", "Hello");
    ft_printf("pointer: %p\n", &x);
    ft_printf("decimal: %d\n", -42);
    ft_printf("integer: %i\n", 123);
    ft_printf("unsigned: %u\n", 4294967295u);
    ft_printf("hex lower: %x\n", 255);
    ft_printf("hex upper: %X\n", 255);
    ft_printf("percent: %%\n");
    
    ft_printf("\n=== Test 2: Multiple variables ===\n");
    ft_printf("Mix: %c %s %d %x %p\n", 'Z', "test", 42, 255, &x);
    
    ft_printf("\n=== Test 3: Five variables ===\n");
    ft_printf("v1=%d, v2=%d, v3=%d, v4=%d, v5=%d\n", 10, 20, 30, 40, 50);
    
    ft_printf("\n=== Test 4: Edge cases ===\n");
    ft_printf("NULL string: %s\n", NULL);
    ft_printf("Zero: %d\n", 0);
    ft_printf("Negative: %d\n", -2147483648);
    
    return 0;
}

// int main() {
//     int num = 42;
//     void *ptr = &num;
    
//     printf("=== Testing all conversions ===\n\n");
    
//     printf("--- %%c (character) ---\n");
//     ft_printf("Character: %c\n", 'A');
//     ft_printf("Multiple: %c %c %c\n", 'X', 'Y', 'Z');
    
//     printf("\n--- %%s (string) ---\n");
//     ft_printf("String: %s\n", "Hello World");
//     ft_printf("Multiple: %s and %s\n", "First", "Second");
//     ft_printf("Null string: %s\n", NULL);
    
//     printf("\n--- %%p (pointer) ---\n");
//     ft_printf("Pointer: %p\n", ptr);
//     ft_printf("Null pointer: %p\n", NULL);
    
//     printf("\n--- %%d (signed decimal) ---\n");
//     ft_printf("Positive: %d\n", 42);
//     ft_printf("Negative: %d\n", -42);
//     ft_printf("Zero: %d\n", 0);
//     ft_printf("Multiple: %d, %d, %d\n", 10, -20, 30);
    
//     printf("\n--- %%i (signed integer) ---\n");
//     ft_printf("Positive: %i\n", 123);
//     ft_printf("Negative: %i\n", -456);
    
//     printf("\n--- %%u (unsigned decimal) ---\n");
//     ft_printf("Unsigned: %u\n", 4294967295u);
//     ft_printf("Zero: %u\n", 0);
//     ft_printf("Multiple: %u, %u\n", 100, 200);
    
//     printf("\n--- %%x (hexadecimal lowercase) ---\n");
//     ft_printf("Hex: %x\n", 255);
//     ft_printf("Hex: %x\n", 16);
//     ft_printf("Multiple: %x, %x, %x\n", 10, 255, 4096);
    
//     printf("\n--- %%X (hexadecimal uppercase) ---\n");
//     ft_printf("Hex: %X\n", 255);
//     ft_printf("Hex: %X\n", 16);
//     ft_printf("Multiple: %X, %X, %X\n", 10, 255, 4096);
    
//     printf("\n--- %%%% (percent sign) ---\n");
//     ft_printf("Percent: %%\n");
//     ft_printf("Multiple: %% %% %%\n");
    
//     printf("\n--- Mixed conversions ---\n");
//     ft_printf("Mixed: %c, %s, %d, %x, %p, %%\n", 
//               'A', "test", 42, 255, ptr);
    
//     printf("\n--- Five variables example ---\n");
//     ft_printf("v1=%d, v2=%s, v3=%c, v4=%x, v5=%u\n",
//               100, "Hello", 'Z', 255, 4294967295u);
    
//     return 0;
// }