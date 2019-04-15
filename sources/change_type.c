/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:26:31 by vkremen           #+#    #+#             */
/*   Updated: 2018/12/20 15:26:34 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		find_num(int i, int j, t_list_all list)
{
	int		num;
	int		x;
	int		y;
	int		min_n;

	x = -1;
	min_n = -1;
	while (g_map[++x] != NULL)
	{
		y = -1;
		while (g_map[x][++y])
			if (g_map[x][y] == list.en_b[0] || g_map[x][y] == list.en_b[1])
			{
				num = return_num(i, j, x, y);
				if (min_n == -1)
					min_n = num;
				else if (min_n > num)
					min_n = num;
			}
	}
	return (min_n);
}

void	fin_fill(t_list_all list)
{
	int		i;
	int		j;

	i = 0;
	while (g_map[i] != NULL)
	{
		j = 0;
		while (g_map[i][j])
		{
			if (g_map[i][j] != list.en_b[0] || g_map[i][j] != list.en_b[1])
				g_cp_map[i][j] = find_num(i, j, list);
			j++;
		}
		i++;
	}
}

int		change_en_type(t_list_all list)
{
	int			count;
	static int	old_count = 0;

	count = check_count(list);
	if (old_count == count)
		return (1);
	else
	{
		fin_fill(list);
		old_count = count;
		return (0);
	}
}
