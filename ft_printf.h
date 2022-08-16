/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:52:07 by sabazyan          #+#    #+#             */
/*   Updated: 2022/05/06 12:22:55 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putstr(char	*s);
int	test_base(char	*base, int num);
int	ft_putnbr_base(size_t nbr, char	*base);
int	ft_putnbr_base_ptr(size_t nbr, char	*base);
int	return_value(int i);
#endif
