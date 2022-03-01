/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eayyildi <ayyildiz_enes66@hotmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:58:00 by eayyildi          #+#    #+#             */
/*   Updated: 2022/01/09 16:58:00 by eayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include<unistd.h>
#include<stdio.h>

int	ft_printf(const char *str, ...);
void ft_putstr(char *s, int *x);
void ft_putchar(char a, int *x);
void ft_putnbr(int n, int *x);
void ft_putunbr(unsigned int n, int *x);

#endif
