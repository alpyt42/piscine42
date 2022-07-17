/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:44:48 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/12 13:16:40 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	get_letter(int i)
{
	char	res;

	res = '\0';
	if (i == 10)
		res = 'a';
	else if (i == 11)
		res = 'b';
	else if (i == 12)
		res = 'c';
	else if (i == 13)
		res = 'd';
	else if (i == 14)
		res = 'e';
	else if (i == 15)
		res = 'f';
	return (res);
}

void	hexfunction(unsigned char c)
{
	int	j;
	int	bashex;
	int	modulo;
	int	moduloint;
	int	temp;

	j = c;
	bashex = j / 16 + 48;
	modulo = j % 16;
	moduloint = j % 16 + 48;
	write (1, "\\", 1);
	write (1, &bashex, 1);
	if (bashex >= 1 && modulo >= 10)
	{
		temp = get_letter(modulo);
		write (1, &temp, 1);
	}
	else
		write (1, &moduloint, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{	
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		if (str[i] >= 127 || str[i] <= 31)
			hexfunction(str[i]);
		i++;
	}
}
