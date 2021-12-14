/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 03:23:13 by cmarouf           #+#    #+#             */
/*   Updated: 2021/10/17 15:06:33 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_put_unsigned_nbr(unsigned int nb)
{
	if (nb >= 10)
		ft_put_unsigned_nbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}

int	ft_putunbr(va_list argf)
{
	unsigned int	nb;

	nb = va_arg(argf, unsigned int);
	ft_put_unsigned_nbr(nb);
	return (ft_get_udeclen(nb));
}
