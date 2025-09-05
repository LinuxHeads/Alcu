/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:16:19 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/05 16:58:01 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "alcu.h"

#define LOST 0
#define WIN 1
#define ERROR -1

void    game_loop(int *map)
{
    int i = 0;
    while (map[i])
        i++;
    
    int player;
    int AI;
    while (1)
    {
        print_map(map, i);
        AI = AI_turn(map);
        ft_putendl_fd("Ai took 1 item", 1);
        if (AI == LOST)
        {
            // end_game(player);
            return;
        }
        print_map(map, i);
        player = player_turn(map);
        if (player == LOST)
        {
            // end_game(player);
            return;
        }
        else if (player == ERROR)
        {
            // end_game(player);
            return;
        }
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

    game_loop(heaps);
    return 0;
}
