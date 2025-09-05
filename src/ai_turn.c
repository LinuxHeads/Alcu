/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:55:30 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/05 20:02:14 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int count_non_empty_heaps(int *map)
{
    int count = 0;
    int i = 0;
    
    while (map[i] != -1)  // -1 marks end of array
    {
        if (map[i] > 0)
            count++;
        i++;
    }
    return count;
}

int ai_move(int heap, int non_empty_heaps)
{
    // If only one heap left (endgame in Misère Nim)
    if (non_empty_heaps == 1)
    {
        // In Misère Nim, we want to leave an odd number of items
        // so the opponent is forced to take the last item
        if (heap <= 3)
        {
            return heap - 1; // Leave 1 item for opponent to take
        }
        else
        {
            // Leave heap size that forces opponent into bad position
            int leave = heap % 4;
            if (leave == 0)
                return 3; // Leave 1 item
            else if (leave == 1)
                return 1; // Leave 0 items - we lose, so take all but 1
            else
                return leave - 1; // Leave 1 item
        }
    }
    
    // Multiple heaps: play normal Nim strategy
    // Try to make nimber (XOR) = 0, or take 1-3 items optimally
    int take = 1;
    if (heap >= 3)
        take = 3;
    else if (heap >= 2)
        take = 2;
    else
        take = 1;
        
    return take;
}

int    AI_turn(int *map)
{
    int i = 0;
    int move;
    int non_empty_heaps;
    int chosen_heap = -1;
    int best_heap = -1;
    int max_items = 0;
    
    // Count non-empty heaps and find the heap with most items
    non_empty_heaps = count_non_empty_heaps(map);
    
    // Find the last non-empty heap and the one with most items
    i = 0;
    while (map[i] != -1)
    {
        if (map[i] > 0)
        {
            chosen_heap = i; // Last non-empty heap (will be updated as we go)
            if (map[i] > max_items)
            {
                max_items = map[i];
                best_heap = i;
            }
        }
        i++;
    }
    
    // Choose strategy based on game state
    if (non_empty_heaps == 1)
    {
        // Only one heap left - use endgame strategy on the last heap
        i = chosen_heap;
    }
    else
    {
        // Multiple heaps - prefer the last non-empty heap (traditional Nim play)
        i = chosen_heap;
    }
    
    move = ai_move(map[i], non_empty_heaps);
    
    // Ensure we don't take more items than available
    if (move > map[i])
        move = map[i];
    
    // Ensure we take at least 1 and at most 3 items
    if (move < 1)
        move = 1;
    if (move > 3)
        move = 3;
    
    remove_from_map(&map[i], move);
    
    // Print how many items AI took
    ft_putstr_fd("AI took ", 1);
    ft_putnbr_fd(move, 1);
    ft_putendl_fd(" item(s)", 1);
    
    // Check if AI took the last item (loses in Misère Nim)
    int total_items = 0;
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
