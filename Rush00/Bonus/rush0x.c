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

int	get_char_index(int x, int y, int xi, int yi)
{
	if (xi == 0 && yi == 0)
		return (0);
	else if (xi == x - 1 && yi == 0)
		return (2);
	else if (xi == 0 && yi == y - 1)
		return (6);
	else if (xi == x - 1 && yi == y - 1)
		return (4);
	else if (yi == 0)
		return (1);
	else if (xi == x - 1)
		return (3);
	else if (yi == y - 1)
		return (5);
	else if (xi == 0)
		return (7);
	else
		return (8);
}

void	rush(int x, int y, char *chars)
{
	int		xi;
	int		yi;
	int		char_index;
	char	c;

	if (x > 0 && y > 0)
	{
		xi = 0;
		yi = 0;
		while (yi < y)
		{
			xi = 0;
			while (xi < x)
			{
				char_index = get_char_index(x, y, xi, yi);
				c = chars[char_index];
				ft_putchar(c);
				xi++;
			}
			ft_putchar('\n');
			yi++;
		}
	}
}
