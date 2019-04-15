/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:08:30 by vkremen           #+#    #+#             */
/*   Updated: 2018/12/22 16:08:35 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	check_player(t_list_all *list)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strstr(line, "$$$ exec p1 : ")
		&& ft_strstr(line, "vkremen.filler"))
	{
		list->my_b = "Oo";
		list->en_b = "Xx";
	}
	else if (ft_strstr(line, "$$$ exec p2 : ")
		&& ft_strstr(line, "vkremen.filler"))
	{
		list->my_b = "Xx";
		list->en_b = "Oo";
	}
	else
	{
		free(line);
		exit(1);
	}
	free(line);
}

int		check_map_size(char **line, t_list_all *list)
{
	if (g_map == NULL)
	{
		list->map_row = ft_atoi(ft_strchr((*line), ' '));
		list->map_col = ft_atoi(ft_strrchr((*line), ' '));
		free((*line));
		if (!(g_map = (char**)malloc(sizeof(char*) * (list->map_row + 1))))
			return (0);
		if (get_map(list) == 0)
			return (0);
		return (1);
	}
	else
	{
		free((*line));
		if (change_map(list) == 0)
			return (0);
		return (1);
	}
}

int		check_piece_size(char **line, t_list_all *list, char ***piece)
{
	list->piece_row = ft_atoi(ft_strchr((*line), ' '));
	list->piece_col = ft_atoi(ft_strrchr((*line), ' '));
	free((*line));
	if (!((*piece) = (char**)malloc(sizeof(char*) * (list->piece_row + 1))))
		return (0);
	if (get_piece(list, piece) == 0)
	{
		free_leaks_piece((*piece));
		return (0);
	}
	return (1);
}

int		check_fig_and_map(int i, int j, t_list_all *list, char **piece)
{
	int		x;
	int		y;
	int		count;

	x = -1;
	count = 0;
	while (piece[++x] != NULL)
	{
		y = -1;
		if (g_map[i + x] == NULL)
			return (-1);
		while (piece[x][++y])
		{
			if (g_map[i + x][j + y] == '\0')
				return (-1);
			else if (piece[x][y] == '*' && (g_map[i + x][j + y]
				== list->my_b[0] || g_map[i + x][j + y] == list->my_b[1]))
				count++;
			else if (piece[x][y] == '*' && (g_map[i + x][j + y]
				== list->en_b[0] || g_map[i + x][j + y] == list->en_b[1]))
				return (-1);
		}
	}
	return (count);
}

int		check_count(t_list_all list)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (g_map[i] != NULL)
	{
		j = 0;
		while (g_map[i][j])
		{
			if (g_map[i][j] == list.en_b[0] || g_map[i][j] == list.en_b[1])
			{
				g_cp_map[i][j] = 0;
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}
