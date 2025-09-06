/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:55:30 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/06 15:39:52 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int calculate_ai_move(int heap_size, int non_empty_heaps,int final)
{
    // If only one heap left (endgame in Misère Nim)
    if (non_empty_heaps == 1)
    {
        // In Misère Nim, we want to leave an odd number of items
        // so the opponent is forced to take the last item
        if (heap_size <= 3)
        {
            if (heap_size == 1)
                return (1); // Forced to take the last item (lose)
            else
                return (heap_size - 1); // Leave 1 item for opponent
        }
        else
        {
            // Leave heap size that forces opponent into bad position
            int leave = heap_size % 4;
            if (leave == 0)
                return (3); // Leave 1 item
            else if (leave == 1)
                return (1); // Leave 0 items - we lose anyway
            else
                return (leave - 1); // Leave 1 item
        }
    }
    else if (final == 1 || final == 5)
    {
        // if last heap contain 1 or 5 try to be the last on this heap
        if (heap_size <= 3)
        {
            return (heap_size); // Leave 1 item for opponent
        }
        else
        {
            return (1);
        }
    }
    // Multiple heaps: play standard strategy
    // Try to take items optimally, preferring to take more when possible
    if (heap_size >= 3)
        return (3);
    else if (heap_size >= 2)
        return (2);
    else
        return (1);
}

int apply_ai_strategy(int *map)
{
    int last_heap_index;
    int non_empty_heaps;
    int move;
    
    // Find the last available heap (where we must take from)
    last_heap_index = find_last_heap(map);
    if (last_heap_index == -1)
        return (LOST); // No heaps available
    
    // Count how many heaps still have items
    non_empty_heaps = count_non_empty_heaps(map);
    
    // Calculate optimal move based on game state
    move = calculate_ai_move(map[last_heap_index], non_empty_heaps, map[0]);
    
    // Ensure move is valid
    if (move > map[last_heap_index])
        move = map[last_heap_index];
    if (move < 1)
        move = 1;
    if (move > 3)
        move = 3;
    
    // Apply the move
    remove_from_map(&map[last_heap_index], move);
    
    // Announce AI's move
    ft_putstr_fd("AI took ", 1);
    ft_putnbr_fd(move, 1);
    ft_putendl_fd("", 1);
    
    return (move);
}

int ai_turn(int *map)
{
    int move;
    int total_items;
    
    // Apply AI strategy and get the move made
    move = apply_ai_strategy(map);
    if (move == LOST)
        return (LOST);
    
    // Check if AI took the last item (loses in Misère Nim)
    total_items = calculate_total_items(map);
    if (total_items == 0)
        return (LOST);
    
    return (WIN);
}
