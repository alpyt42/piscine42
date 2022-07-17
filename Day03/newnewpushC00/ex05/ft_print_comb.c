/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:09:22 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/07 17:38:02 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int i, int i2, int i3)

{
	write (1, &i, 1);
	write (1, &i2, 1);
	write (1, &i3, 1);
	if (i != 55)
	{
		write (1, ", ", 2);
	}
}

void	ft_print_comb(void)

{
	int	i;
	int	i2;
	int	i3;

	i = 48;
	while (i < 58)
	{
		i2 = i + 1;
		while (i2 < 58)
		{
			i3 = i2 + 1;
			while (i3 < 58)
			{
				ft_print (i, i2, i3);
				i3 ++;
			}
			i2 ++;
		}
		i ++;
	}
}
