/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:16:19 by abdsalah          #+#    #+#             */
/*   Updated: 2025/09/06 13:16:21 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;
	int		*heaps;

	if (argc > 2)
	{
		ft_putendl_fd("Usage: ./alum1 [map file]", 1);
		return (1);
	}
	fd = 0;
	if (argc == 2)
	{
		fd = setup_input_file(argv[1]);
	}
	map = read_and_store_map(fd);
	if (!map)
		return (1);
	heaps = str_map_to_int(map);
	ft_free_2d(map);
	if (!heaps)
		return (1);
	game_loop(heaps);
	free(heaps);
	return (0);
}
