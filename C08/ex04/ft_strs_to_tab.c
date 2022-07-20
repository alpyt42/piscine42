/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:36:02 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/20 17:58:28 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strdup(char *src)
{
	int		len;
	char	*tab;
	char	*ptr;

	len = 0;
	while (src[len])
		len++;
	tab = (char *)malloc(sizeof(*src) * (len + 1));
	ptr = tab;
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (tab);
}

int	ft_strlen(char *av)
{
	int	len;

	len = 0;
	while (av[len])
		len++;
	return (len);
}

struct s_stock_str	*ft_str_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stock;

	stock = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	i = 0;
	if (!stock)
		return ((void *)0);
	while (i < ac && av[i])
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = av[i];
		stock[i].copy = ft_strdup(av[i]);
		i++;
	}
	stock[i].str = (void *)0;
	return (stock);
}
