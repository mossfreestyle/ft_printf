/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:46:54 by rwassim           #+#    #+#             */
/*   Updated: 2025/04/29 12:06:47 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_isformat(char c);
int	ft_hexa(unsigned int nb, char c);
int	ft_format(va_list args, char c);
int	ft_printu(unsigned int nb);
int	ft_ptr(unsigned long nb);
int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putstr(char *str);
int	ft_printf(const char *format, ...);

#endif
