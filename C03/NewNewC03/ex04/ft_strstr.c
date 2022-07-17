/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:39:51 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/14 10:39:40 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	search_char(int i, char *str, char *to_find)
{
	int		time;
	int		j;

	time = 0;
	j = 0;
	while (to_find[j] && time == 0)
	{
		if (str[i] != to_find[j])
			time = 1;
		i++;
		j++;
		if (to_find[j] == '\0' && time == 0)
			return (1);
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		res;
	char	*temp;

	i = 0;
	res = 0;
	j = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			temp = &str[i];
			res = search_char(i, str, to_find);
			if (res == 1)
				return (temp);
		}
		i++;
	}
	return (0);
}
