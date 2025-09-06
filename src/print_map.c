/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 00:18:56 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/06 13:06:47 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static int print_spaces(int count)
{
    int i = 0;
    while(i < count)
    {
        ft_putchar_fd(' ', 1);
        i++;
    }
    return (i);
}

static void print_heap(int heap)
{
    int j = 0;
    while(j < heap)
    {
        if (j > 30)
        {
            ft_putchar_fd('(', 1);
            ft_putnbr_fd(heap - 30, 1);
            ft_putchar_fd(')', 1);
            break;
        }
        ft_putchar_fd('|', 1);
        if (j < heap - 1)
            ft_putchar_fd(' ', 1);
        j++;
    }
}

void print_map(int *map, int map_size)
{
    int i;
    int max;

    i = 0;
    max = 0;
    while(map[i] != -1 && i < map_size)
    {
        if (map[i] > max)
            max = map[i];
        i++;
    }
    i = 0;
    while(i < map_size && map[i] != -1)
    {
        print_spaces(((max - map[i]) / 2) % 30);
        print_heap(map[i]);
        ft_putchar_fd('\n', 1);
        i++;
    }
}
