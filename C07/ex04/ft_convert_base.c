/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:15:50 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/19 17:28:36 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(long nbr, char *base_to);

int	ft_base_error(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == '\0' || base[i + 1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32
			|| base[i] >= 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_sign(char *str, int i)
{
	int	sign;

	sign = 1;
	while ((str[i] == '+' || str[i] == '-') && str[i])
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base_from)
{
	int			i;
	long int	nbr;
	int			lbase;
	int			sign;

	i = 0;
	nbr = 0;
	lbase = 0;
	sign = 1;
	while (base_from[lbase])
		lbase++;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = ft_sign(str, i);
	while ((str[i] == '+' || str[i] == '-') && str[i])
		i++;
	while (str[i] && ft_is_in_base(str[i], base_from) != -1)
	{
		nbr = nbr * lbase + ft_is_in_base(str[i], base_from);
		i++;
	}
	return (nbr * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	res_nbr;
	char	*res_char;

	if (ft_base_error(base_from) == 0 || ft_base_error(base_to) == 0)
		return (NULL);
	else
	{
		res_nbr = ft_atoi_base(nbr, base_from);
		res_char = ft_itoa(res_nbr, base_to);
	}
	return (res_char);
}
