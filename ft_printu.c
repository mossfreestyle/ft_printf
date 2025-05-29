/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:28:28 by rwassim           #+#    #+#             */
/*   Updated: 2025/04/29 12:08:19 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printu(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
		len += ft_printu(nb / 10);
	len += ft_putchar((nb % 10) + '0');
	return (len);
}
