/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:19:22 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/06 00:19:59 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

# include "../libft/include/libft.h"
# include <unistd.h>
# include <fcntl.h>

# define LOST 0
# define WIN 1
# define ERROR -1

char    **read_and_store_map(int fd);
int     *str_map_to_int(char **map);
int	    ft_isnumber_endl(char *str);
void    print_map(int *map, int i);
int     player_turn(int *map);
int     AI_turn(int *map);
int     remove_from_map(int *map, int num);
void    end_game(int player,int bot);
int     setup_input_file(char *file_name);
char	**ft_free_2d(char **str);
void    game_loop(int *map);

int     find_last_heap(int *map);
int     count_non_empty_heaps(int *map);
int     calculate_total_items(int *map);
int     calculate_ai_move(int heap_size, int non_empty_heaps);
int     apply_ai_strategy(int *map);

#endif // ALCU_H