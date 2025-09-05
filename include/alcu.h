/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:19:22 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/05 15:22:29 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

#include "../libft/include/libft.h"

int *str_map_to_int(char **map);
char **read_and_store_map(void);
int	ft_isnumber_endl(char *str);

#endif // ALCU_H