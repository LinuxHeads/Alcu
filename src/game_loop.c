/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 00:19:32 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/06 13:24:34 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void	end_game(int player, int bot)
{
	if (player == LOST)
	{
		ft_putendl_fd("Player has took the last item, player lose\n AI Winns",
			1);
		ft_putendl_fd("********************************", 1);
		ft_putendl_fd("*********** AI Winns ***********", 1);
		ft_putendl_fd("********************************", 1);
	}
	else if (bot == LOST)
	{
		ft_putendl_fd("AI has took the last item, AI lose", 1);
		ft_putendl_fd("********************************", 1);
		ft_putendl_fd("********* Player Winns *********", 1);
		ft_putendl_fd("********************************", 1);
	}
	else if (player == ERROR)
	{
		ft_putendl_fd("The game stopped due to player request, \nClosing...",
			1);
	}
}

void	game_loop(int *map)
{
	int	i;
	int	player;
	int	ai;

	i = 0;
	while (map[i] != -1)
		i++;
	player = WIN;
	ai = WIN;
	while (1)
	{
		print_map(map, i);
		ai = ai_turn(map);
		if (ai == LOST)
		{
			end_game(player, ai);
			return ;
		}
		print_map(map, i);
		player = player_turn(map);
		if (player == LOST || player == ERROR)
		{
			end_game(player, ai);
			return ;
		}
	}
}
