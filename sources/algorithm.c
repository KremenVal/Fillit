/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:26:14 by vkremen           #+#    #+#             */
/*   Updated: 2019/01/12 19:07:25 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	fill_struct(int i, int j, t_list_all **list, char **piece)
{
	int		count;

	if (check_fig_and_map(i, j, (*list), piece) == 1)
	{
		count = return_count(i, j, piece);
		if ((*list)->sum == 0)
		{
			(*list)->sum = count;
			(*list)->cord_x = i;
			(*list)->cord_y = j;
		}
		else if (count < (*list)->sum)
		{
			(*list)->sum = count;
			(*list)->cord_x = i;
			(*list)->cord_y = j;
		}
	}
}

int		algorithm(t_list_all *list, char **piece)
{
	int		i;
	int		j;

	i = 0;
	fill_cp_map(*list);
	while (g_map[i] != NULL)
	{
		j = 0;
		while (g_map[i][j])
		{
			fill_struct(i, j, &list, piece);
			j++;
		}
		i++;
	}
	ft_printf("%d %d\n", list->cord_x, list->cord_y);
	free_leaks_piece(piece);
	if (list->sum == 0)
		return (0);
	else
		return (1);
}
