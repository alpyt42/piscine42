/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:02:23 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/07 19:52:22 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)

{
	write(1, &a, 1);
}

void	ft_putnbr(int nb)

{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	if (nb >= 0 && nb < 10)
		ft_putchar(nb + '0');
	if (nb < 0 && nb != -2147483648)
	{
		ft_putchar('-');
		ft_putnbr(nb * (-1));
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
