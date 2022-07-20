/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:30:18 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/20 09:45:05 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_sep(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_nbr_str(char *str, char *charset)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (check_sep(charset, str[i]) == 0 && str[i])
			nb++;
		while (check_sep(charset, str[i]) == 0 && str[i])
			i++;
		while (check_sep(charset, str[i]) == 1 && str[i])
			i++;
	}
	return (nb);
}

int	ft_strlen(char *str, char *charset)
{
	int	len;

	len = 0;
	while (check_sep(charset, str[len]) == 0 && str[len])
		len++;
	return (len);
}

char	*ft_string(char *str, int len)
{
	int		i;
	char	*tab;

	i = 0;
	tab = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len && str[i])
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	split = (char **)malloc(sizeof(char *) * (ft_nbr_str(str, charset) + 1));
	while (str[i])
	{
		while (str[i] && check_sep(charset, str[i]) == 1)
			i++;
		if (str[i])
		{
			split[j] = ft_string(&str[i], ft_strlen(&str[i], charset));
			i += ft_strlen(&str[i], charset);
			j++;
		}
	}
	split[j] = '\0';
	return (split);
}
