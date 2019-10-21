/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_north.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:46:32 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/21 21:13:50 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		**ft_go_north1(t_map *tmp, int **int_map, int k)
{
	int l;
	int	n;

	if (tmp->tmp_i >= 0)
	{
		n = tmp->tmp_j - 1;
		l = k;
		while (n >= 0)
		{
			if (int_map[tmp->tmp_i][n] == 0 ||
			(int_map[tmp->tmp_i][n] != 0 && int_map[tmp->tmp_i][n] > l))
				int_map[tmp->tmp_i][n] = l;
			l++;
			n--;
		}
	}
	return (int_map);
}

int		**ft_go_north2(t_map *tmp, int **int_map, int k)
{
	int l;
	int	n;

	if (tmp->tmp_i < tmp->height)
	{
		n = tmp->tmp_j + 1;
		l = k;
		while (n < tmp->width)
		{
			if (int_map[tmp->tmp_i][n] == 0 ||
			(int_map[tmp->tmp_i][n] != 0 && int_map[tmp->tmp_i][n] > l))
				int_map[tmp->tmp_i][n] = l;
			l++;
			n++;
		}
	}
	return (int_map);
}

int		**ft_go_north(t_map *tmp, int **int_map, int i, int j)
{
	int	k;

	k = 1;
	while (i >= 0 && int_map[i][j] != tmp->his_order)
	{
		if (int_map[i][j] == 0 || (int_map[i][j] != 0 && int_map[i][j] > k))
			int_map[i][j] = k;
		k++;
		tmp->tmp_i = i;
		tmp->tmp_j = j;
		int_map = ft_go_north1(tmp, int_map, k);
		int_map = ft_go_north2(tmp, int_map, k);
		i--;
	}
	return (int_map);
}
