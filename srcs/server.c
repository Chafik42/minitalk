/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:58:26 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/16 15:12:37 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minitalk.h"

static t_bit	g_bit;

void	binary_to_ascii(int bit)
{
	if (bit == 31)
		g_bit.c += g_bit.n;
	if (g_bit.n == 1)
		g_bit.n = 2;
	else
		g_bit.n *= 2;
}

void	get_pid(int bit)
{
	binary_to_ascii(bit);
	g_bit.size++;
	if (g_bit.size == 31)
	{
		if (g_bit.c)
		{
			g_bit.client_pid *= 10;
			g_bit.client_pid += (g_bit.c - 48);
		}
		if (!g_bit.c)
			g_bit.end = 1;
		g_bit.c = 0;
		g_bit.n = 1;
		g_bit.size = 0;
	}
}

void	decrypting(int bit)
{
	binary_to_ascii(bit);
	g_bit.size++;
	if (g_bit.size == 31)
	{
		write(1, &g_bit.c, 1);
		if (!g_bit.c)
		{
			g_bit.end = 0;
			write(1, "\n", 1);
			kill(g_bit.client_pid, SIGUSR2);
			g_bit.client_pid = 0;
		}
		g_bit.c = 0;
		g_bit.n = 1;
		g_bit.size = 0;
	}
}

int	main(void)
{
	int	pid;

	g_bit.end = 0;
	g_bit.client_pid = 0;
	g_bit.c = 0;
	g_bit.n = 1;
	g_bit.size = 0;
	pid = getpid();
	ft_printf("Server PID is : %d\n", pid);
	while (1)
	{
		while (g_bit.end == 0)
		{
			signal(SIGUSR2, get_pid);
			signal(SIGUSR1, get_pid);
			pause();
		}
		signal(SIGUSR2, decrypting);
		signal(SIGUSR1, decrypting);
		pause();
	}
}
