/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_turn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:05:07 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/05 16:51:24 by abdsalah         ###   ########.fr       */
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
    
    while (map[i] == 0)
        i++;

    while (1)
    {
        items = take_input();
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