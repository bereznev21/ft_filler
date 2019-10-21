/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:15:05 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/21 16:37:41 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft/includes/libft.h"
# include <stdio.h>

typedef struct		s_map
{
	int			my_order;
	int			his_order;
	int			height;
	int			width;
	char		**map;
}					t_map;

typedef struct		s_figure
{
	int			best_i;
	int			best_j;
	int			figure_a;
	int			figure_b;
	uintmax_t	best_sum;
	char		**figure;
}					t_figure;

#endif

void	ft_srch_figure(t_figure *fig, char *line);
void	ft_srch_figure_size(t_figure *fig, char *line);
void	ft_write_map(t_map *tmp, char *line);
void	ft_free_map(int **tmp, int width);
void	ft_create_map(t_map *tmp);
int		ft_srch_map(t_map *tmp);
void	ft_srch_order(char *line, t_map *tmp);
void	ft_srch_size(char *line, t_map *tmp);
void	ft_crt_figure(t_figure *tmp);
int		**ft_heatmap(int **int_map, t_map *tmp);
void	ft_start_heat_map(t_map *tmp, int **int_map, int i, int j);
int		**ft_go_north(t_map *tmp, int **int_map, int i, int j);
int		**ft_go_south(t_map *tmp, int **int_map, int i, int j);
int		**ft_go_east(t_map *tmp, int **int_map, int i, int j);
int		**ft_go_west(t_map *tmp, int **int_map, int i, int j);
void	ft_insert_figure(t_map *tmp, t_figure *fig, int **int_map);
void	ft_write_figure(t_map *tmp, t_figure *fig);
void	ft_free_char(char **map, int width);
void	ft_free_int(int **map, int width);
void	ft_free(t_map *tmp, t_figure *fig);
