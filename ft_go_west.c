/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_west.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:46:24 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/21 18:46:26 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		**ft_go_west(t_map *tmp, int **int_map, int i, int j)
{
	int	k;
	int l;
	int	n;

	k = 1;
	while (j >= 0 && int_map[i][j] != tmp->his_order)
	{
		if (int_map[i][j] == 0 || (int_map[i][j] != 0 && int_map[i][j] > k))
			int_map[i][j] = k;
		k++;
		if (i > 0)
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
		if (i < tmp->height)
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
		j--;
	}
	return (int_map);
}
