/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:09:49 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/20 17:28:32 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
