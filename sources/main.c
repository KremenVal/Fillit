/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:59:00 by vkremen           #+#    #+#             */
/*   Updated: 2018/12/17 17:59:01 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		lets_play(t_list_all *list)
{
	char	*line;
	char	**piece;

	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Plateau"))
		{
			if (check_map_size(&line, list) == 0)
				return (0);
		}
		else if (ft_strstr(line, "Piece"))
		{
			if (check_piece_size(&line, list, &piece) == 0)
				return (0);
			return (algorithm(list, piece));
		}
		else
		{
			if (line != NULL)
				free(line);
			return (0);
		}
	}
	return (1);
}

int		main(void)
{
	t_list_all		list;

	list.sum = 0;
	check_player(&list);
	while (1)
	{
		if (lets_play(&list) == 0)
			break ;
		list.sum = 0;
		list.cord_x = 0;
		list.cord_y = 0;
	}
	return (0);
}
