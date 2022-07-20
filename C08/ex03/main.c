/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:50:58 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/20 13:28:46 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"
void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}
int	main(void)
{
	t_point point;
	set_point(&point); 
	return (0);
}
