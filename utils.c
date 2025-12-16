/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:08:42 by yafakihi          #+#    #+#             */
/*   Updated: 2025/12/16 16:07:55 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_putchar(int c){
    write(1, &c, 1);
    return (1);
}

int ft_putstr(char *str)
{
    int i;
    int len = 0;
    i = 0;
    while (str[i])
    {
        len += ft_putchar(str[i]);
        i++;
    }
    return (len);
}


void ft_putnbr(int n)
{
    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
    {
        ft_putnbr(n / 10);
    }
    ft_putchar((n % 10) + '0');
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

int ft_putnbr_unsigned(unsigned int n){
    
    int count = 0;
    
    if(n >= 10)
        count += ft_putnbr_unsigned(n / 10);
    ft_putchar((n % 10) + '0');
    count++;
    return count;
}

int ft_putptr(void *ptr)
{
    unsigned long address;
    int count = 0;

    if (!ptr)
        return ft_putstr("(nil)");

    address = (unsigned long)ptr;

    count += ft_putstr("0x");
    count += ft_puthex(address, 0);

    return count;
}




// int main ()
// {
//     // int len = 0;
//     int x = ft_putstr("abc");
//     // printf("\n%d", x);
//     return (0);
// }