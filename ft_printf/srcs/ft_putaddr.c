/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 03:20:43 by cmarouf           #+#    #+#             */
/*   Updated: 2021/10/17 19:39:34 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putaddr(long unsigned int n, int k, char *base)
{
	if (n == 0)
		return ;
	if (k == 1)
	{
		ft_putchar('0');
		ft_putchar('x');
		k--;
	}
	if (n >= 16)
		ft_putaddr(n / 16, k, base);
	ft_putchar(base[n % 16]);
}

int	ft_putaddress(va_list argf, int k, char *base)
{
	long unsigned int	n;

	n = va_arg(argf, long unsigned int);
	ft_putaddr(n, k, base);
	return (ft_get_adresslen(n));
}
