/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01al.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:08:02 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/17 13:56:42 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int *ft_evidence(int tab[6][6])
{
	int	x;
	int	y;
	int incr;

	x = 1;
	y = 1;
	incr = 1;
	while (y < 5)
	{
		if (tab[0][y] == 4)
		{
			while (x < 5)
			{
				tab[x][y] = incr;
				incr++;
				x++;
			}
		}
		if (tab[0][y] == 1)
			tab[1][y] = 4;
		x = 4;
		incr = 1;
		if (tab[5][y] == 4)
		{
			while (x > 1)
			{
				tab[x][y] = incr;
				incr++;
				x--;
			}
		}
		if (tab[5][y] == 1)
			tab[4][y] = 4;
		incr = 1;
		x = 1;
		y++;
	}
	y = 1;
	while (x < 5)
	{
		if (tab[x][0] == 4)
		{
			while (y < 5)
			{
				tab[x][y] = incr;
				incr++;
				y++;
			}
		}
		if (tab[x][0] == 1)
			tab[x][1] = 4;
		y = 4;
		incr = 1;
		if (tab[x][5] == 4)
		{
			while (y > 1)
			{
				tab[x][y] = incr;
				incr++;
				y--;
			}
		}
		if (tab[x][5] == 1)
			tab[x][4] = 4;
		incr = 1;
		y = 1;
		x++;
	}
	return (tab[6]);
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

	i = 0;
	j = 0;

	while (i < 6)
	{
		while (j < 6)
		{
			printf("%d ", tab[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
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
	int check;

	j = 0;
	k = 1;
	l = 0;
	check = 0;
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

int missing_online(int nb, int tab[6][6],int y)
{
    int x;

    x = 1;
    while (x < 5)
    {
        if (tab[x][y] == nb)
            return (0);
        x++;   
    }
    return (1);
}

int missing_on_col(int nb, int tab[6][6], int x)
{
    int y;

    y = 1;
    while (y < 5)
    {
        if (tab[x][y] == nb)
            return (0);
        y++;   
    }
    return (1);
}

int good_nb(int k, tab[6][6], int x, int y)
{
    int i;
    int j;
    int count;
    int 

    i = 1;
    j = 1;
    count = 0;

    while (i < 5)
        {
            if ()
            if (count == tab[0][y] && i == 4)
                temp = 1;
            
            i++;
        }
}

int is_valid(int tab[6][6], int x, int y)
{
	int	k;

	k = 1;
	if (x * y == 16)
		return (1);
	if (x == 4)
	{
		y += 1;
		x = 1;
	}	
	if (tab[x][y] != 0)
		return (is_valid(tab, x + 1, y));
	while (k <= 4)
		{
			if (missing_on_line(k, tab, y) && missing_on_col(k, tab, x) && good_nb(k, tab, x, y))
			{
				tab[x][y] = k;
				if (is_valid(tab, x + 1, y))
					return (1);
			}
		}
    tab[x][y] = 0;
    return (0);
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
	ft_evidence(tab);
	print_tab(tab);
}

int main(int argc, char **argv)
{
	if (argc <= 1 || argc >= 3)
	{
		write(1, "Error", 5);
		return (0);
	}
	else
		setup_tab(&argv[1]);
	return (0);
}
