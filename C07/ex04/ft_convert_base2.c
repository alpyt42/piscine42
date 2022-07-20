/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:41:33 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/20 09:48:59 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen_res(long nbr, int lbase)
{
	int	len;

	len = 1;
	if (nbr < 0)
		nbr *= -1;
	while (nbr > lbase)
	{
		nbr = nbr / lbase;
		len++;
	}
	return (len);
}

int	ft_strlen(char *base_to)
{
	int	lbase;

	lbase = 0;
	while (base_to[lbase])
		lbase++;
	return (lbase);
}

void	ft_rev(char *tab, int size)
{
	int		i;
	char	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i++;
	}
}

char	*fill_tab(char *base_to, int len_res, long nbr, int lbase)
{
	char	*tab;
	int		i;
	int		temp;

	i = 0;
	temp = 0;
	tab = malloc(sizeof(char) * len_res + 1);
	while (nbr != 0)
	{
		tab[i++] = base_to[nbr % lbase];
		nbr = nbr / lbase;
		temp = 1;
	}
	if (len_res == 1 && nbr == 0 && temp == 0)
		tab[0] = base_to[0];
	return (tab);
}

char	*ft_itoa(long nbr, char *base_to)
{
	char	*tab;
	int		i;
	int		len_res;
	int		lbase;
	int		sign;

	i = 0;
	sign = 1;
	lbase = ft_strlen(base_to);
	len_res = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		sign = -1;
		len_res++;
	}
	len_res += ft_strlen_res(nbr, lbase);
	tab = fill_tab(base_to, len_res, nbr, lbase);
	if (sign == -1)
		tab[len_res - 1] = '-';
	ft_rev(tab, len_res);
	tab[len_res] = '\0';
	return (tab);
}
