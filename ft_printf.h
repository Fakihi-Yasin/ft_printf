/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 03:27:03 by yafakihi          #+#    #+#             */
/*   Updated: 2025/12/20 15:19:44 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putstr(const char *str);
int	ft_putchar(char c);
int	ft_puthex(unsigned long n, int uppercase);
int	ft_putptr(void *ptr);
int	ft_printf(const char *format, ...);
#endif