/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:08:42 by yafakihi          #+#    #+#             */
/*   Updated: 2025/12/20 02:24:21 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int ft_putchar(char c) {
    return write(1, &c, 1);
}

int ft_putstr(char *s) {
    int count = 0;
    if (!s)
        return ft_putstr("(null)");
    while (*s) {
        count += ft_putchar(*s);
        s++;
    }
    return count;
}

int ft_putnbr(int n) {
    int count = 0;
    long num = n;
    
    if (num < 0) {
        count += ft_putchar('-');
        num = -num;
    }
    if (num >= 10)
        count += ft_putnbr(num / 10);
    count += ft_putchar((num % 10) + '0');
    return count;
}

int ft_putnbr_unsigned(unsigned int n) {
    int count = 0;
    
    if (n >= 10)
        count += ft_putnbr_unsigned(n / 10);
    count += ft_putchar((n % 10) + '0');
    return count;
}
int ft_puthex(unsigned long n, int uppercase)
{
    char *hex_digits;
    int count;

    count = 0;
    if (uppercase)
        hex_digits = "0123456789ABCDEF";
    else
        hex_digits = "0123456789abcdef";

    if (n >= 16)
        count += ft_puthex(n / 16, uppercase);

    count += ft_putchar(hex_digits[n % 16]);
    return (count);
}

int ft_putptr(void *ptr) {
    int count = 0;
    unsigned long addr = (unsigned long)ptr;
    
    count += ft_putstr("0x");
    count += ft_puthex(addr, 0);
    return count;
}




// int main ()
// {
//     // int len = 0;
//     int x = ft_putstr("abc");
//     // printf("\n%d", x);
//     return (0);
// }