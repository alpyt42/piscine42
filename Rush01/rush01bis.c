/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:52:37 by ale-cont          #+#    #+#             */
/*   Updated: 2022/07/16 15:02:52 by ale-cont         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int    str_len(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    print_tab(int **tab)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 6)
    {
        while (j < 6)
        {
            write(1, &tab[i][j], 1);
            j++;
        }
        write(1, "\n", 2);
        i++;
    }
}

int **fill_row(int **tab, char **argv, int str_pos)
{
    int j;
    int k;

    j = 1;
    k = 0;
    while (argv[str_pos])
    {
        if ((int)argv[str_pos] == 32 && j < 5)
        {
            tab[j][k] = (int)argv[str_pos - 1] - 48;
            printf(" test1 =%d ", tab[j][k]);
            j++;
        }
        else if (j == 4)
        {
            j = 0;
            k = 5;
        }
        str_pos++;
    }
    return tab;
}

int    **fill_col(int **tab, char **argv)
{
    int i;
    int j;
    int k;
    int fill_col;

    i = 0;
    j = 0;
    k = 1;
    fill_col = 0;
    while (argv[i])
    {
        if (fill_col == 1)
            fill_row(tab, argv, i);

        if ((int)argv[i] == 32 && k < 5 && fill_col == 0)
        {
            tab[j][k] = (int)*argv[i - 1];
            printf(" test =%d ",  (int)*argv[i - 1]);
            k++;
        }
        if (k == 4 && fill_col == 0 && j == 0)
        {
            j = 5;
            k = 0;
        }
        if (k == 4 && j == 5)
            fill_col = 1;
        printf("%d", (int)argv[i- 1]);
        i++;
    }
    return tab;
}

void     setup_tab(char **argv)
{
    int **tab;
    int i;

    i = 0;
    tab = (int**)malloc(str_len(argv) * 6);
    while (i < str_len(*argv) && argv[i])
    {
        tab[i] = (int*)malloc(str_len(*argv) * 6);
        i++;
    }
    fill_col(tab, argv);
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
