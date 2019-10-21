/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_east.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:46:19 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/21 20:58:14 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		**ft_go_east1(t_map *tmp, int **int_map, int k)
{
	int l;
	int	n;

	if (tmp->tmp_j > 0)
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

int		**ft_go_east2(t_map *tmp, int **int_map, int k)
{
	int l;
	int	n;

	if (tmp->tmp_j < tmp->width)
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

int		**ft_go_east(t_map *tmp, int **int_map, int i, int j)
{
	int	k;

	k = 1;
	while (j < tmp->width && int_map[i][j] != tmp->his_order)
	{
		if (int_map[i][j] == 0 || (int_map[i][j] != 0 && int_map[i][j] > k))
			int_map[i][j] = k;
		k++;
		tmp->tmp_i = i;
		tmp->tmp_j = j;
		int_map = ft_go_east1(tmp, int_map, k);
		int_map = ft_go_east2(tmp, int_map, k);
		j++;
	}
	return (int_map);
}
