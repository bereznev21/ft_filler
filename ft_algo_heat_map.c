/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_heat_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:33:46 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/11 23:37:49 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		**ft_go_north(t_map *tmp, int **int_map, int i, int j)
{
	int	k;

	k = 0;
	while (int_map[i][j] != -1 && i > 0)
	{
		//printf("%d", int_map[i][j]);
		//int_map = ft_go_west(tmp, int_map, i, j);
		//int_map = ft_go_east(tmp, int_map, i, j);
		int_map[i][j] = k++;
		i--;
	}
	//printf("\n");
	return (int_map);
}

int		**ft_go_south(t_map *tmp, int **int_map, int i, int j)
{
	int	k;

	k = 0;
	while (int_map[i][j] != -1 && i < tmp->height)
	{
		//int_map = ft_go_east(tmp, int_map, i, j);
		int_map[i][j] = k++;
		i++;
	}
	return (int_map);
}

int		**ft_go_east(t_map *tmp, int **int_map, int i, int j)
{
	int	k;

	k = 0;
	while (int_map[i][j] != -1 && j < tmp->width)
	{
		int_map[i][j] = k++;
		j++;
	}
	return (int_map);
}

int		**ft_go_west(t_map *tmp, int **int_map, int i, int j)
{
	int	k;

	k = 0;
	while (int_map[i][j] != -1 && j >= 0)
	{
		int_map[i][j] = k++;
		j--;
	}
	return (int_map);
}

void	ft_start_heat_map(t_map *tmp, int **int_map, int i, int j)
{
	int_map = ft_go_north(tmp, int_map, i, j);
	int_map = ft_go_south(tmp, int_map, i, j);
	int_map = ft_go_east(tmp, int_map, i, j);
	int_map = ft_go_west(tmp, int_map, i, j);
	//printf("%d\n", int_map[8][2]);
}
