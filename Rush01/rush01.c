/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01al.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:08:02 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/17 16:41:26 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int missing_on_line (int nb, int tab[6][6], int x)
{
	int y;

	y = 1;
	while(y < 5)
	{
		if (tab[x][y] == nb)
			return 0;
		y++;
	}
	return 1;
}

int missing_on_col(int nb, int tab[6][6], int y)
{
	int x;

	x = 1;
	while (x < 5)
	{
		if (tab[x][y] == nb)
			return 0;
		x++;
	}
	return 1;
}

int check_col_up(int tab[6][6], int x)
{
	int y;
	int count;
	int max;

	y = 1;
	count = 1;
	max = tab[x][y];
	
	while (y < 5)
	{
		if (max < tab[x][y + 1])
		{
			max = tab[x][y + 1];
			count++;
		}
		y++;	
	}
	if (count == tab[x][0])
		return 1;
	return 0;
}

int check_col_down(int tab[6][6], int x)
{
	int y;
	int count;
	int max;

	y = 4;
	count = 1;
	max = tab[x][y];
	
	while (y > 1)
	{
		if (max < tab[x][y - 1])
		{
			max = tab[x][y - 1];
			count++;
		}
		y--;	
	}
	if (count == tab[x][0])
		return 1;
	return 0;
}

int check_line_left(int tab[6][6], int y)
{
	int x;
	int count;
	int max;

	x = 1;
	count = 1;
	max = tab[x][y];
	
	while (x < 5)
	{
		if (max < tab[x + 1][y])
		{
			max = tab[x + 1][y];
			count++;
		}
		x++;	
	}
	if (count == tab[0][y])
		return 1;
	return 0;
}

int check_line_right(int tab[6][6], int y)
{
	int x;
	int count;
	int max;

	x = 4;
	count = 1;
	max = tab[x][y];
	
	while (x > 1)
	{
		if (max < tab[x - 1][y])
		{
			max = tab[x - 1][y];
			count++;
		}
		x--;	
	}
	if (count == tab[0][y])
		return 1;
	return 0;
}

int is_valid (int tab[6][6], int x, int y)
{	
	int nb;

	nb = 1;
//	if (x * y == 25)
	if(check_col_up(tab, x) && check_col_down(tab, x) && check_line_left(tab, y) && check_line_right(tab, y))	
		return 1;
	if (x == 5)
	{
		x = 1;
		y += 1;
	}
	if (tab[x][y] != 0)
		return is_valid(tab, x + 1, y);

	while (nb < 5)
	{
		if (missing_on_line(nb, tab, x) && missing_on_col(nb, tab, y))
		{
			tab[x][y] = nb;	
			if (is_valid(tab, x + 1, y))
				return 1;
		}
		nb++;
	}

	tab[x][y] = 0;
	return 0;
}


int    str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void    print_tab(int tab[6][6])
{
	int i;
	int j;

	i = 1;
	j = 1;

	while (i < 5)
	{
		while (j < 5)
		{
			printf("%d ", tab[i][j]);
			j++;
		}
		printf("\n");
		j = 1;
		i++;
	}
}

int *fill_row(int tab[6][6], char **argv, int str_pos)
{
	int i;
	int j;
	int k;

	j = 1;
	k = 0;
	while (argv[0][str_pos])
	{
		if(argv[0][str_pos + 1] == '\0')
			tab[4][5] = (int)argv[0][str_pos] - 48;
		if (argv[0][str_pos] == ' ' && j < 6)
		{
			tab[j][k] = (int)argv[0][str_pos - 1] - 48;
			j++;
		}
		else if (j == 5 && k == 0)
		{
			j = 1;
			k = 5;
		}
		str_pos++;
	}
	return (tab[6]);
}

int    *fill_col(int tab[6][6], char **argv)
{
	int j;
	int k;
	int l;

	j = 0;
	k = 1;
	l = 0;
	while (argv[0][l] && l < 16)
	{
		if (argv[0][l] == ' ' && k < 6)
		{
			tab[j][k] = (int)argv[0][l - 1] - 48;
			k++;
		}
		if (k == 5)
		{
			j = 5;
			k = 1;
		}
		l++;
	}
	fill_row(tab, argv, l);
	return (tab[6]);
}

void     setup_tab(char **argv)
{
	int tab[6][6];
	int i = 0;
	int j = 0;
	while (i < 6)
	{
		while (j < 6)
		{
			tab[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}

	fill_col(tab, argv);
//	ft_evidence(tab);
	is_valid(tab, 1, 1);
	print_tab(tab);
}


int main(int argc, char **argv)
{
	if (argc <= 1 || argc >= 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
		setup_tab(&argv[1]);
	return (0);
}
