/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:38:00 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/19 13:01:35 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int	ft_strlen_total(int size, char **strs, char *sep)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	if (size == 0)
		return (0);
	while (i < size)
	{
		total = total + ft_strlen(strs[i]);
		i++;
	}
	return (total += ft_strlen(sep) * size -1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	int		t;
	char	*res;

	k = 0;
	i = 0;
	res = malloc(sizeof(char) * (ft_strlen_total(size, strs, sep) + 1));
	while (k < ft_strlen_total(size, strs, sep))
	{
		j = 0;
		t = 0;
		while (strs[i][j])
			res[k++] = strs[i][j++];
		if (i < size - 1)
		{
			while (sep[t])
				res[k++] = sep[t++];
			i++;
		}
	}
	res[k] = '\0';
	return (res);
}
