/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:16:19 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/05 15:25:23 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "alcu.h"



void    game_loop(int *map)
{
    while (1)
    {
        print_map(map);
        // Ai turn
        // check lose
        // player turn
        // check lose
    }
    
}

int main(void)
{
    char **map = read_and_store_map();
    if (!map)
        return (1);
    int *heaps = str_map_to_int(map);
    if (!heaps)
        return (1);
    int i = 0;
    while (heaps[i])
    {
        printf("heaps [%d] : %d",i,heaps[i]);
        i++;
    }    
    print_map(heaps);

    // game_loop(heaps);
    return 0;
}
