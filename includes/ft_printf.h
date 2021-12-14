/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 03:30:51 by cmarouf           #+#    #+#             */
/*   Updated: 2021/10/20 01:32:33 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *str, ...);

int		ft_putaddress(va_list argf, int k, char *base);
int		ft_putunbr(va_list argf);
int		ft_putnbr_base16(va_list argf, char *base);
int		ft_putnbrf(va_list argf);
int		ft_get_declen(int nb);
int		ft_get_hexlen(unsigned int nb);
int		ft_get_udeclen(unsigned int nb);
int		ft_get_adresslen(long unsigned int nb);
int		ft_putstrf(va_list argf);
int		ft_putcharf(va_list argf);
int		ft_putchar(char c);

#endif
