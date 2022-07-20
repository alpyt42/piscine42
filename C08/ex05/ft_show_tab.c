/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:02:14 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/20 18:38:28 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (par[i].str)
	{
		j = 0;
		k = 0;
		ft_putchar(par[i].size + 48);
		ft_putchar("\n");
		while (par[i].str[j])
			ft_putchar(par[i].str[j++]);
		ft_putchar("\n");
		while (par[i].copy[k])
			ft_putchar(par[i].copy[k++]);
		ft_putchar("\n");
		i++;
	}
}
