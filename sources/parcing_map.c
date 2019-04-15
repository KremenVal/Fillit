/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:34:50 by vkremen           #+#    #+#             */
/*   Updated: 2018/12/20 12:34:53 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		check_line(char *map, char *str)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (ft_strchr(str, map[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	change_map_sec_part(char *line, int i)
{
	int		j;

	j = 0;
	while (g_map[i][j])
	{
		if ((*line >= '0' && *line <= '9') || *line == ' ')
			line++;
		else
		{
			g_map[i][j++] = *line;
			line++;
		}
	}
}

int		change_map(t_list_all *list)
{
	int		i;
	int		j;
	char	*line;
	char	*str;

	i = -1;
	get_next_line(0, &line);
	free(line);
	while (g_map[++i] != NULL)
	{
		get_next_line(0, &line);
		str = line;
		j = 0;
		change_map_sec_part(line, i);
		free(str);
		if ((int)ft_strlen(g_map[i]) != list->map_col)
			return (0);
		if (check_line(g_map[i], ".oOxX") == 0)
			return (0);
	}
	if (i != list->map_row)
		return (0);
	return (1);
}

int		get_map(t_list_all *list)
{
	int		i;
	char	*line;

	i = 0;
	get_next_line(0, &line);
	free(line);
	while (i < list->map_row)
	{
		get_next_line(0, &line);
		g_map[i] = ft_strdup((char*)line + 4);
		free(line);
		if (check_line(g_map[i], ".oOxX") == 0)
			return (0);
		if ((int)ft_strlen(g_map[i]) != list->map_col)
			return (0);
		i++;
	}
	g_map[i] = NULL;
	if (i != list->map_row)
		return (0);
	return (1);
}

int		get_piece(t_list_all *list, char ***piece)
{
	int		i;
	char	*line;

	i = 0;
	while (i < list->piece_row)
	{
		get_next_line(0, &line);
		(*piece)[i] = ft_strdup(line);
		free(line);
		if (check_line((*piece)[i], ".*") == 0)
		{
			(*piece)[++i] = NULL;
			return (0);
		}
		if ((int)ft_strlen((*piece)[i]) != list->piece_col)
		{
			(*piece)[++i] = NULL;
			return (0);
		}
		i++;
	}
	(*piece)[i] = NULL;
	if (i != list->piece_row)
		return (0);
	return (1);
}
