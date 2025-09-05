/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_turn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:05:07 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/05 19:57:21 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static int take_input()
{
    int num = 0;
    char *in = NULL;
    
    while (1)
    {
        ft_putstr_fd("please choose between 1 - 3 items: ", 1);
        in = get_next_line(0);
        if (!in)
        {
            return (-1);
        }
        if (!ft_isnumber_endl(in))
        {
            ft_putendl_fd("invalid user input", 1);
            free(in);
            continue;
        }
        num = ft_atoi(in);
        if(num < 1 || num > 3)
        {
            ft_putendl_fd("input should be between 1 - 3 items", 1);
            free(in);
            continue;
        }

        free(in);
        return (num);       
    }
    return (num);    
}

int remove_from_map(int *map, int num)
{
    if(*map - num < 0)
    {
        ft_putendl_fd("not enongh items in the row, choose again.", 1);
        return (0);
    }
    *map = *map - num;
    return(1);
}

int player_turn(int *map)
{
    int i = 0;
    int items;
    int total_items;
    int last_heap = -1;
    
    // Find the last non-empty heap
    while (map[i] != -1)
    {
        if (map[i] > 0)
            last_heap = i;
        i++;
    }
    
    i = last_heap; // Start from the last non-empty heap

    while (1)
    {
        items = take_input();
        if (items == -1)
        {
            return ERROR;
        }
        if (remove_from_map(&map[i], items))
            break ;
    }
    
    // Check if player took the last item (loses in Misère Nim)
    total_items = 0;
    i = 0;
    while (map[i] != -1)
    {
        total_items += map[i];
        i++;
    }
    
    if (total_items == 0)
        return LOST;
    
    return WIN;
}