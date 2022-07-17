/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush0X.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:32:55 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/09 11:37:25 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_pos_char(int x, int y, int xi, int yi)
{
	if (xi == 0 && yi == 0)
		ft_putchar('A');
	else if (xi == x - 1 && yi == 0)
		ft_putchar('C');
	else if (xi == 0 && yi == y - 1)
		ft_putchar('C');
	else if (xi == x - 1 && yi == y - 1)
		ft_putchar('A');
	else if (xi == 0 || yi == 0 || xi == x - 1 || yi == y - 1)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int		xi;
	int		yi;

	if (x > 0 && y > 0)
	{
		xi = 0;
		yi = 0;
		while (yi < y)
		{
			xi = 0;
			while (xi < x)
			{
				print_pos_char(x, y, xi, yi);
				xi++;
			}
			ft_putchar('\n');
			yi++;
		}
	}
}
