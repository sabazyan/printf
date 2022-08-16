/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:29:42 by sabazyan          #+#    #+#             */
/*   Updated: 2022/05/06 12:20:01 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_format(int letter, int count, va_list ap)
{
	if (letter == 'c')
		count = ft_putchar(va_arg(ap, int));
	else if (letter == 's')
	{
		count = ft_putstr(va_arg(ap, char *));
	}
	else if (letter == 'd' || letter == 'i')
		count = ft_putnbr(va_arg(ap, int));
	else if (letter == 'x' || letter == 'X')
	{
		if (letter == 'x')
			count = ft_putnbr_base(va_arg(ap, int), "0123456789abcdef");
		else
			count = ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
	}
	else if (letter == 'p')
	{
		write(1, "0x", 2);
		count = ft_putnbr_base_ptr(va_arg(ap, long int), "0123456789abcdef");
	}
	else if (letter == 'u')
		count = ft_putnbr_base(va_arg(ap, int), "0123456789");
	else if (letter == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += get_format(str[i + 1], count, ap);
			i += 2;
		}
		else
		{
			write(1, &str[i++], 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
