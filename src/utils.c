/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:22:08 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/05 15:23:20 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
static void print_map(int *map)
{
    int i;
    int j;
    int max;
    int spaces;

    i = 0;
    max = 0;
    while(map[i])
    {
        if (map[i] > max)
            max = map[i];
        i++;
    }
    i--;
    while(map[i])
    {
        spaces = (max - map[i]/ 2);
        while(spaces)
        {
            ft_putchar_fd(' ', 1);
            spaces--;
        }
        j = 0;
        while(j < map[i])
        {
            ft_putchar_fd('|', 1);
            j++;
        }
        ft_putchar_fd('\n', 1);
        i--;
    }
}

int	ft_isnumber_endl(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
        {
            if (str[i] == '\n' && i == ft_strlen(str) - 1)
            {
                i++;
                continue;
            }
			return (0);
        }
		i++;
	}
	return (1);
}
