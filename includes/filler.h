/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:42:44 by vkremen           #+#    #+#             */
/*   Updated: 2018/12/17 18:43:25 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct			s_list_all
{
	int					map_row;
	int					map_col;
	int					piece_row;
	int					piece_col;
	int					cord_x;
	int					cord_y;
	int					sum;
	char				*my_b;
	char				*en_b;
}						t_list_all;

char					**g_map;
int						**g_cp_map;
void					check_player(t_list_all *list);
int						lets_play(t_list_all *list);
int						check_map_size(char **line, t_list_all *list);
int						get_map(t_list_all *list);
int						check_line(char *map, char *str);
int						change_map(t_list_all *list);
void					change_map_sec_part(char *line, int i);
int						check_piece_size(char **line, t_list_all *list,
											char ***piece);
int						get_piece(t_list_all *list, char ***piece);
int						algorithm(t_list_all *list, char **piece);
void					fill_cp_map(t_list_all list);
void					fill_int_mass(t_list_all list);
int						change_en_type(t_list_all list);
int						check_count(t_list_all list);
void					fin_fill(t_list_all list);
int						find_num(int i, int j, t_list_all list);
int						return_num(int i, int j, int x, int y);
void					fill_struct(int i, int j, t_list_all **list,
									char **piece);
int						check_fig_and_map(int i, int j, t_list_all *list,
									char **piece);
int						return_count(int i, int j, char **piece);
void					free_leaks_piece(char **piece);

#endif
