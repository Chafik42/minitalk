/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_adresslen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:16:07 by cmarouf           #+#    #+#             */
/*   Updated: 2021/10/17 23:24:35 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_get_adresslen(long unsigned int nb)
{
	int	len;

	len = 2;
	if (nb == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	while (nb > 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}
