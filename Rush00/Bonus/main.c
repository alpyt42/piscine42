/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:30:16 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/09 11:30:36 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	rush(int x, int y, char *chars);

int	main(void)
{
	rush(5, 5, "o-o|o-o| ");
	ft_putchar('\n');
	rush(5, 5, "/*\\*/*\\* ");
	ft_putchar('\n');
	rush(5, 5, "ABABCBCB ");
	ft_putchar('\n');
	rush(5, 5, "ABCBCBAB ");
	ft_putchar('\n');
	rush(5, 5, "ABCBABCB ");
	return (0);
}
