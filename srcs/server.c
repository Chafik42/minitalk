/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:58:26 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/14 13:27:02 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minitalk.h"

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID is : %d\n", pid);
	/*while (1)
	{
		signal(SIGUSR1, &handler);
		signal(SIGUSR2, &handler);
		pause();
	}*/
	return (0);
}
