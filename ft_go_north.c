/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_north.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:46:32 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/21 18:46:33 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		**ft_go_north(t_map *tmp, int **int_map, int i, int j)
{
	int	k;
	int l;
	int	n;

	k = 1;
	while (i >= 0 && int_map[i][j] != tmp->his_order)
	{
		if (int_map[i][j] == 0 || (int_map[i][j] != 0 && int_map[i][j] > k))
			int_map[i][j] = k;
		k++;
		if (i >= 0)
		{
			n = j - 1;
			l = k;
			while (n >= 0)
			{
				if (int_map[i][n] == 0 ||
				(int_map[i][n] != 0 && int_map[i][n] > l))
					int_map[i][n] = l;
				l++;
				n--;
			}
		}
		if (i < tmp->height)
		{
			n = j + 1;
			l = k;
			while (n < tmp->width)
			{
				if (int_map[i][n] == 0 ||
				(int_map[i][n] != 0 && int_map[i][n] > l))
					int_map[i][n] = l;
				l++;
				n++;
			}
		}
		i--;
	}
	return (int_map);
}
