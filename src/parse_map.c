/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:21:17 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/06 13:08:49 by abdsalah         ###   ########.fr       */
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
            return (NULL);
    }
    // Check if no input was provided (Ctrl+D immediately)
    if (ft_strlen(str) == 0)
    {
        free(str);
        return (NULL);
    }
    
    result = ft_split(str,',');
    free(str);
    return (result);
}

int *str_map_to_int(char **map)
{
    int i = 0;
    int *result;
    
    // Check if map is NULL or empty
    if (!map || !map[0])
        return (NULL);
    // Count number of lines in map
    while (map[i])
        i++;
    // Check if no valid heaps were found
    if (i == 0)
        return (NULL);
    result = malloc(sizeof(int) * (i + 1));
    if (!result)
        return (NULL);
    
    int j = 0;
    while (j < i && map[j])
    {
        if (!ft_isnumber_endl(map[j]))
        {
            ft_putendl_fd("ERROR", 2);
            free(result);
            return (NULL);
        }
        result[j] = ft_atoi(map[j]);
        if (result[j] < MIN_ITEMS || result[j] > MAX_ITEMS)
        {
            ft_putendl_fd("ERROR", 2);
            free(result);
            return (NULL);
        }
        j++;
    }
    result[j] = -1;
    return (result);
}
