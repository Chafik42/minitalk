/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:25:22 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/14 18:33:49 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minitalk.h"

int	check(char i)
{
	if (i >= '0' && i <= '9')
		return (1);
	if (i == '+' || i == '-')
		return (2);
	if ((i >= 9 && i <= 13) || i == ' ')
		return (3);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	nbr;
	int		sign;

	i = 0;
	sign = 1;
	nbr = 0;
	while (check(nptr[i]) == 3)
		i++;
	if (check(nptr[i]) == 2)
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (check(nptr[i]) == 1)
	{
		if (nbr * sign > 2147483647)
			return (-1);
		else if (nbr * sign < -2147483648)
			return (0);
		nbr = nbr * 10 + nptr[i++] - 48;
	}
	return (nbr * sign);
}

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}
