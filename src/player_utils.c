/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:25:40 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/06 13:25:54 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int find_last_heap(int *map)
{
    int i = 0;
    int last_heap = -1;
    
    while (map[i] != -1)
    {
        if (map[i] > 0)
            last_heap = i;
        i++;
    }
    return (last_heap);
}

int count_non_empty_heaps(int *map)
{
    int count = 0;
    int i = 0;
    
    while (map[i] != -1)
    {
        if (map[i] > 0)
            count++;
        i++;
    }
    return (count);
}

int calculate_total_items(int *map)
{
    int total = 0;
    int i = 0;
    
    while (map[i] != -1)
    {
        total += map[i];
        i++;
    }
    return (total);
}