/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:21:56 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/18 16:07:20 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	i;
	int	*tab;

	i = 0;
	if (min >= max)
		return ((void *)0);
	len = max - min;
	if (len < 0)
		len = len * -1;
	tab = (int *)malloc(sizeof(*tab) * len);
	while (min < max)
		tab[i++] = min++;
	return (tab);
}
