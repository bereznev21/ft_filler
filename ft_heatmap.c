/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:05:31 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/21 18:22:02 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		**ft_crt_int_map(t_map *tmp, int **int_map)
{
	int	index;

	index = 0;
	if (!(int_map = (int**)malloc(sizeof(int*) * (tmp->height))))
		return (0);
	while (index < tmp->height)
		if (!(int_map[index++] = (int*)malloc(sizeof(int) * (tmp->width))))
			return (0);
	return (int_map);
}

int		**ft_write_int_map(t_map *tmp, int **int_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < tmp->height)
	{
		while (j < tmp->width)
		{
			if (tmp->map[i][j] == '.')
				int_map[i][j] = 0;
			if (tmp->map[i][j] == 'O' || tmp->map[i][j] == 'o')
				int_map[i][j] = -1;
			if (tmp->map[i][j] == 'X' || tmp->map[i][j] == 'x')
				int_map[i][j] = -2;
			j++;
		}
		j = 0;
		i++;
	}
	return (int_map);
}

int		**ft_write_heat_map(t_map *tmp, int **int_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < tmp->height)
	{
		while (j < tmp->width)
		{
			if (int_map[i][j] == tmp->his_order)
				ft_start_heat_map(tmp, int_map, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	return (int_map);
}

int		**ft_heatmap(int **int_map, t_map *tmp)
{
	int_map = ft_crt_int_map(tmp, int_map);
	int_map = ft_write_int_map(tmp, int_map);
	int_map = ft_write_heat_map(tmp, int_map);
	return (int_map);
}
