/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cp_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:29:20 by vkremen           #+#    #+#             */
/*   Updated: 2018/12/20 14:29:21 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	fill_int_mass(t_list_all list)
{
	int		i;
	int		j;

	i = 0;
	while (i < list.map_row)
	{
		j = 0;
		while (g_cp_map[i][j] != -2)
		{
			g_cp_map[i][j] = -1;
			j++;
		}
		i++;
	}
	g_cp_map[i] = 0;
}

void	fill_cp_map(t_list_all list)
{
	int			i;
	static int	j = 0;

	if (g_cp_map == NULL)
	{
		if (!(g_cp_map = (int**)malloc(sizeof(int*) * list.map_row + 1)))
			return ;
		i = 0;
		while (i < list.map_row)
		{
			if (!(g_cp_map[i] = (int*)malloc(sizeof(int) * list.map_col)))
				return ;
			g_cp_map[i][list.map_col] = -2;
			i++;
		}
		fill_int_mass(list);
	}
	if (j == 0)
		j = change_en_type(list);
}
