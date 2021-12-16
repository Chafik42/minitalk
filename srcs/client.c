/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:14:28 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/16 17:21:37 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minitalk.h"

void	encrypting(int pid, unsigned char *msg, int len)
{
	int			i;
	int			decalage;

	i = 0;
	while (i <= len)
	{
		decalage = 0;
		while (decalage < 31)
		{
			if ((msg[i] >> decalage) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			decalage++;
			usleep(50);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	char	*c_pid;

	c_pid = ft_itoa(getpid());
	if (ac != 3)
	{
		ft_printf("Wrong number of arguments\n");
		ft_printf("Typo is ./client PID MSG  \n");
		free(c_pid);
		return (0);
	}
	if (kill(ft_atoi(av[1]), 0) == -1)
	{
		ft_printf("ERROR : This pid leads no were\n");
		free(c_pid);
		return (0);
	}
	encrypting(ft_atoi(av[1]), (unsigned char *)c_pid, ft_strlen(c_pid));
	usleep(50);
	encrypting(ft_atoi(av[1]), (unsigned char *)av[2], ft_strlen(av[2]));
	free(c_pid);
	return (0);
}
