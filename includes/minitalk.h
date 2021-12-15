/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:10:44 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/15 17:38:13 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../ft_printf/ft_printf.h"
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_atoi(const char *nptr);
int	ft_strlen(char *str);

typedef struct s_bit
{
	int					size;
	wchar_t				c;
	int					n;
}				t_bit;

#endif
