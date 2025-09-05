/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:21:17 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/05 15:23:13 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

char **read_and_store_map(void)
{
    char **result;
    char *str;
    char *line;
    char *temp;
    
    str = ft_strdup("");
    if (!str)
        return (NULL);
    while (1)
    {
        line = get_next_line(0);
        if (!line || line[0] == '\0' || line[0] == '\n')
        {
            free(line);
            break;
        }
        line = ft_strjoin(line,",");
        temp = ft_strjoin(str,line);
        free(str);
        str = temp;
        free(line);
        line = NULL;
    }
    result = ft_split(str,',');
    return (result);
}

int *str_map_to_int(char **map)
{
    int i = 0;
    int *result;
    
    while (map[i])
    {
        i++;
    }
    result = malloc(sizeof(int) * (i + 1));
    if (!result)
    {
        return (NULL);
    }
    i--;
    int j = 0;
    while (map[i] && i >= 0)
    {
        if (!ft_isnumber_endl(map[i]))
        {
            ft_putendl_fd("Error: The board containes non number elements", 2);
            free(result);
            return (NULL);
        }
        result[j] = ft_atoi(map[i]);
        if (result[j] < 1 || result[j] > 10000)
        {
            ft_putendl_fd("Error: Each line should contain number between 1 and 10000", 2);
            free(result);
            return (NULL);
        }
        i--;
        j++;
    }
    result[j] = 0;
    return (result);
}
