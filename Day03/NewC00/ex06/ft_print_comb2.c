/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:41:22 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/07 11:55:27 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printputchar(char c)

{
	write(1, &c, 1);
}

void	ft_print(int a, int b)

{
	int	amodulo;
	int	bmodulo;
	int	b1;
	int	a1;

	bmodulo = (b % 10 + 48);
	a1 = (a / 10 + 48);
	b1 = (b / 10 + 48);
	amodulo = (a % 10 + 48);
	printputchar(a1);
	printputchar(amodulo);
	printputchar(' ');
	printputchar(b1);
	printputchar(bmodulo);
	if (a < 98)
	{
		write (1, ", ", 1);
	}
}

void	ft_print_comb2(void)

{
	char	a;
	char	b;

	a = 0;
	b = 1;
	while (a < 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_print(a, b);
			b++;
		}
		a++;
	}
}
