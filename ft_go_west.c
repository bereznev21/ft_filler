/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_west.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:46:24 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/21 21:10:26 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		**ft_go_west1(t_map *tmp, int **int_map, int k)
{
	int l;
	int	n;

	if (tmp->tmp_i > 0)
	{
		n = tmp->tmp_i - 1;
		l = k;
		while (n >= 0)
		{
			if (int_map[n][tmp->tmp_j] == 0 ||
			(int_map[n][tmp->tmp_j] != 0 && int_map[n][tmp->tmp_j] > l))
				int_map[n][tmp->tmp_j] = l++;
			n--;
		}
	}
	return (int_map);
}

int		**ft_go_west2(t_map *tmp, int **int_map, int k)
{
	int l;
	int	n;

	if (tmp->tmp_i < tmp->height)
	{
		n = tmp->tmp_i + 1;
		l = k;
		while (n < tmp->height)
		{
			if (int_map[n][tmp->tmp_j] == 0 ||
			(int_map[n][tmp->tmp_j] != 0 && int_map[n][tmp->tmp_j] > l))
				int_map[n][tmp->tmp_j] = l++;
			n++;
		}
	}
	return (int_map);
}

int		**ft_go_west(t_map *tmp, int **int_map, int i, int j)
{
	int	k;

	k = 1;
	while (j >= 0 && int_map[i][j] != tmp->his_order)
	{
		if (int_map[i][j] == 0 || (int_map[i][j] != 0 && int_map[i][j] > k))
			int_map[i][j] = k;
		k++;
		tmp->tmp_i = i;
		tmp->tmp_j = j;
		int_map = ft_go_west1(tmp, int_map, k);
		int_map = ft_go_west2(tmp, int_map, k);
		j--;
	}
	return (int_map);
}
