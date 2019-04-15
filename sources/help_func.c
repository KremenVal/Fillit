/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:09:39 by vkremen           #+#    #+#             */
/*   Updated: 2018/12/22 16:09:41 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		return_num(int i, int j, int x, int y)
{
	if ((x >= i && y >= j))
		return ((x - i) + (y - j));
	else if ((x >= i && y <= j))
		return ((x - i) + (j - y));
	else if ((x <= i && y >= j))
		return ((i - x) + (y - j));
	else if ((x <= i && y <= j))
		return ((i - x) + (j - y));
	else
		return (1);
}

int		return_count(int i, int j, char **piece)
{
	int		x;
	int		y;
	int		count;

	x = 0;
	count = 0;
	while (piece[x] != NULL)
	{
		y = 0;
		while (piece[x][y])
		{
			if (piece[x][y] == '*')
				count += g_cp_map[i + x][j + y];
			y++;
		}
		x++;
	}
	return (count);
}

void	free_leaks_piece(char **piece)
{
	int i;

	if (!piece || !piece[0])
		return ;
	i = 0;
	while (piece[i] != NULL)
	{
		free(piece[i]);
		piece[i] = NULL;
		i++;
	}
	free(piece);
}
