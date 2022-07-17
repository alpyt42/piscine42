/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:44:05 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/16 10:24:48 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_error(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+' || base[i] <= 32
			|| base[i] >= 127)
			return (1);
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			lbase;
	int long	nb;

	lbase = 0;
	nb = nbr;
	if (ft_error(base) == 1)
		return ;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	while (base[lbase])
		lbase++;
	if (nb >= 0 && nb < lbase)
		ft_putchar(base[nb]);
	else
	{
		ft_putnbr_base(nb / lbase, base);
		ft_putchar(base[nb % lbase]);
	}
}
