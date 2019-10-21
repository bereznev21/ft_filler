/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_east.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:46:19 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/21 19:14:03 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		**ft_go_east(t_map *tmp, int **int_map, int i, int j)
{
	int	k;
	int l;
	int	n;

	k = 1;
	tmp->tmp_i = i;
	tmp->tmp_j = j;
	while (j < tmp->width && int_map[i][j] != tmp->his_order)
	{
		if (int_map[i][j] == 0 || (int_map[i][j] != 0 && int_map[i][j] > k))
			int_map[i][j] = k;
		k++;
		if (j > 0)
		{
			n = i + 1;
			l = k;
			while (n < tmp->height)
			{
				if (int_map[n][j] == 0 ||
				(int_map[n][j] != 0 && int_map[n][j] > l))
					int_map[n][j] = l++;
				n++;
			}
		}
		if (j < tmp->width)
		{
			n = i - 1;
			l = k;
			while (n >= 0)
			{
				if (int_map[n][j] == 0 ||
				(int_map[n][j] != 0 && int_map[n][j] > l))
					int_map[n][j] = l++;
				n--;
			}
		}
		j++;
	}
	return (int_map);
}
