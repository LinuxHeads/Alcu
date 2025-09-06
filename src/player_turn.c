/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_turn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:05:07 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/06 13:08:31 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static int take_input()
{
    int num = 0;
    char *in = NULL;
    
    while (1)
    {
        ft_putstr_fd("Please choose between 1 and 3 items: ", 1);
        in = get_next_line(0);
        if (!in)
            return (-1);
        if (!ft_isnumber_endl(in))
        {
            ft_putendl_fd("Invalid choice", 1);
            free(in);
            continue;
        }
        num = ft_atoi(in);
        if(num < MIN_REMOVAL || num > MAX_REMOVAL)
        {
            ft_putstr_fd(in, 1);
            ft_putendl_fd(" - Invalid choice", 1);
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
        ft_putendl_fd("Not enough items in the heap, choose again.", 1);
        return (0);
    }
    *map = *map - num;
    return(1);
}

int player_turn(int *map)
{
    int items;
    int last_heap_index;
    
    // Find the last non-empty heap (where player must take from)
    last_heap_index = find_last_heap(map);
    if (last_heap_index == -1)
        return (LOST); // No heaps available
    
    // Get player input and validate
    while (1)
    {
        items = take_input();
        if (items == -1)
            return (ERROR);
        if (remove_from_map(&map[last_heap_index], items))
            break ;
    }
    
    // Check if player took the last item (loses in Misère Nim)
    if (calculate_total_items(map) == 0)
        return (LOST);
    
    return (WIN);
}
