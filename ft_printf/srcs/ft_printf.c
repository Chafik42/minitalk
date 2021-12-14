/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 03:29:10 by cmarouf           #+#    #+#             */
/*   Updated: 2021/10/20 01:43:35 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_determine_convertion(char const *str, va_list argf, int index, int len)
{
	if (str[index] == 'c')
		len += ft_putcharf(argf);
	else if (str[index] == 's')
		len += ft_putstrf(argf);
	else if (str[index] == 'p')
		len += ft_putaddress(argf, 1, "0123456789abcdef");
	else if (str[index] == 'd')
		len += ft_putnbrf(argf);
	else if (str[index] == 'i')
		len += ft_putnbrf(argf);
	else if (str[index] == 'u')
		len += ft_putunbr(argf);
	else if (str[index] == 'x')
		len += ft_putnbr_base16(argf, "0123456789abcdef");
	else if (str[index] == 'X')
		len += ft_putnbr_base16(argf, "0123456789ABCDEF");
	else if (str[index] == '%')
		len += ft_putchar('%');
	else if (str[index + 1])
		len += ft_putchar(str[index - 1]);
	else if (!str[index + 1])
		return (-1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	argf;
	int		i;
	int		len;
	int		error;

	va_start(argf, str);
	i = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			error = ft_determine_convertion(str, argf, i + 1, 0);
			len += error;
			i++;
		}
		else if (str[i] == '%')
			error = -1;
		else
			len += write(1, &str[i], 1);
	}
	va_end(argf);
	if (error == -1)
		return (-1);
	return (len);
}
