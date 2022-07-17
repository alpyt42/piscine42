/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:32:14 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/14 12:55:52 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	sizedest;
	unsigned int	i;
	unsigned int	count;
	unsigned int	sizesrc;

	i = 0;
	sizedest = ft_strlen(dest);
	sizesrc = ft_strlen(src);
	count = sizedest;
	if (size == 0 || size <= sizedest)
		return (size + sizesrc);
	while (src[i] && i < size - sizedest - 1)
	{
		dest[count] = src[i];
		i ++;
		count ++;
	}
	dest[count] = '\0';
	return (sizedest + sizesrc);
}
