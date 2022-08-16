/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:58:51 by sabazyan          #+#    #+#             */
/*   Updated: 2022/05/06 12:27:45 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	return_value(int i)
{
	write(1, "0", 1);
	if (i == 1)
		return (1);
	else
		return (3);
}

int	ft_putnbr_base(size_t nbr, char	*base)
{
	int				i;
	int				j;
	int				arr[1000];
	unsigned int	lnbr;

	i = 0;
	j = 0;
	lnbr = nbr;
	if (nbr == 0)
		return (return_value(1));
	while (base[j] != '\0')
		j++;
	while (lnbr > 0)
	{
		arr[i] = lnbr % j;
		lnbr /= j;
		i++;
	}
	j = i;
	if (nbr < 0)
		j++;
	while (--i != -1)
		write(1, &base[arr[i]], 1);
	return (j);
}

int	ft_putnbr_base_ptr(size_t nbr, char	*base)
{
	int						i;
	int						j;
	int						arr[1000];
	unsigned long long int	lnbr;

	i = 0;
	j = 0;
	lnbr = nbr;
	if (nbr == 0)
		return (return_value(2));
	while (base[j] != '\0')
		j++;
	while (lnbr > 0)
	{
		arr[i] = lnbr % j;
		lnbr /= j;
		i++;
	}
	j = i;
	if (nbr < 0)
		j++;
	while (--i != -1)
		write(1, &base[arr[i]], 1);
	return (j + 2);
}
