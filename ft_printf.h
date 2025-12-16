/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 03:27:03 by yafakihi          #+#    #+#             */
/*   Updated: 2025/12/15 15:03:14 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putnbr(int n, int *len);
void	ft_putstr(const char *str, int *len);
void	ft_putchar(char c, int *len);
void	ft_puthex(unsigned long n, int uppercase, int *len);
int		ft_printf(const char *format, ...);
void	ft_putptr(void *ptr, int *len);
#endif