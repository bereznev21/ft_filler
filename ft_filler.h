/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:15:05 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/11 23:03:20 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft/includes/libft.h"
# include <stdio.h>

//int	get_next_line(const int fd, char **line);

typedef struct		s_map
{
	int		height;
	int		width;
	int		order;
	char	**map;
}					t_map;

typedef struct		s_figure
{
	int		figure_a;
	int		figure_b;
	char	**figure;
}					t_figure;

#endif

void	ft_srch_figure(t_map *tmp, t_figure *fig, char *line);
void	ft_write_map(t_map *tmp, char *line);
void	ft_free_map(t_map *tmp);
void	ft_create_map(t_map *tmp);
void	ft_srch_map(t_map *tmp);
void	ft_srch_order(char *line, t_map *tmp);
void	ft_srch_size(char *line, t_map *tmp);
void	ft_crt_figure(t_figure *tmp);
int		**ft_heatmap(t_map *tmp);
void	ft_start_heat_map(t_map *tmp, int **int_map, int i, int j);
int		**ft_go_north(t_map *tmp, int **int_map, int i, int j);
int		**ft_go_south(t_map *tmp, int **int_map, int i, int j);
int		**ft_go_east(t_map *tmp, int **int_map, int i, int j);
int		**ft_go_west(t_map *tmp, int **int_map, int i, int j);
