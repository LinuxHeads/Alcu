/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:55:30 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/05 16:55:59 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int    AI_turn(int *map)
{
    int i = 0;
    int items;
    
    while (map[i] == 0)
        i++;

    while (1)
    {
        items = 1;
        if (items == -1)
        {
            return -1;
        }
        if (remove_from_map(&map[i], items))
            break ;
    }
    if(!map[i] && !map[i + 1])
        return 0;
    return (1);
}
