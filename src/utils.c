/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:22:08 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/06 00:22:01 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

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

int setup_input_file(char *file_name)
{
    int fd = open(file_name, O_RDONLY);
    return (fd);
}

char	**ft_free_2d(char **str)
{
    if (!str || !*str)
        return (NULL);
    int i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
