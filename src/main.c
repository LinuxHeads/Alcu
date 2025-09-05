/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:16:19 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/05 17:43:47 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "alcu.h"

void    game_loop(int *map)
{
    int i = 0;
    while (map[i])
        i++;
    
    int player = WIN;
    int AI = WIN;
    while (1)
    {
        print_map(map, i);
        AI = AI_turn(map);
        ft_putendl_fd("Ai took 1 item", 1);
        if (AI == LOST)
        {
            end_game(player, AI);
            return ;
        }
        print_map(map, i);
        player = player_turn(map);
        if (player == LOST)
        {
            end_game(player, AI);
            return ;
        }
        else if (player == ERROR)
        {
            end_game(player, AI);
            return ;
        }
    }
    
}

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        ft_putendl_fd("Useage: ./alum1 [map file]", 1);
        return (1);
    }
    
    int fd = 0;
    if (argc == 2)
    {
        fd = setup_input_file(argv[1]);
    }
    
    char **map = read_and_store_map(fd);
    if (!map)
        return (1);
        
    int *heaps = str_map_to_int(map);
    // ft_free_2d(map);
    if (!heaps)
        return (1);

    game_loop(heaps);
    
    return 0;
}
