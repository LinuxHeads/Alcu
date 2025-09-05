/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:21:17 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/05 19:57:21 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

char **read_and_store_map(int fd)
{
    char **result;
    char *str;
    char *line;
    char *temp;
    char *temp_line;
    
    str = ft_strdup("");
    if (!str)
        return (NULL);
    while (1)
    {
        line = get_next_line(fd);
        if (!line || line[0] == '\0' || line[0] == '\n')
        {
            free(line);
            break;
        }
        temp_line = ft_strjoin(line,",");
        free(line);
        line = temp_line;
        if (!line)
        {
            free(str);
            return (NULL);
        }
        temp = ft_strjoin(str,line);
        free(str);
        str = temp;
        free(line);
        line = NULL;
        if (!str)
        {
            return (NULL);
        }
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
    int j = 0;
    while (--i >= 0 && map[i])
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
        j++;
    }
    result[j] = -1;
    return (result);
}
