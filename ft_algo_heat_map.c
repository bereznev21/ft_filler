/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_heat_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:33:46 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/20 20:36:38 by rpoetess         ###   ########.fr       */
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
				if (int_map[n][j] == 0 || (int_map[n][j] != 0 && int_map[n][j] > l))
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
				if (int_map[n][j] == 0 || (int_map[n][j] != 0 && int_map[n][j] > l))
					int_map[n][j] = l++;
				n++;
			}
		}
		j--;
	}
	return (int_map);
}

int		**ft_go_east(t_map *tmp, int **int_map, int i, int j)
{
	int	k;
	int l;
	int	n;

	k = 1;
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
				if (int_map[n][j] == 0 || (int_map[n][j] != 0 && int_map[n][j] > l))
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
				if (int_map[n][j] == 0 || (int_map[n][j] != 0 && int_map[n][j] > l))
					int_map[n][j] = l++;
				n--;
			}
		}
		j++;
	}
	return (int_map);
}

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
				if (int_map[i][n] == 0 || (int_map[i][n] != 0 && int_map[i][n] > l))
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
				if (int_map[i][n] == 0 || (int_map[i][n] != 0 && int_map[i][n] > l))
					int_map[i][n] = l;
				l++;
				n++;
			}
		}
		i--;
	}
	return (int_map);
}

int		**ft_go_south(t_map *tmp, int **int_map, int i, int j)
{
	int	k;
	int l;
	int	n;

	k = 1;
	while (i < tmp->height && int_map[i][j] != tmp->his_order)
	{
		if (int_map[i][j] == 0 || (int_map[i][j] != 0 && int_map[i][j] > k))
			int_map[i][j] = k;
		k++;
		if (i >= 0)
		{
			n = j + 1;
			l = k;
			while (n < tmp->width)
			{
				if (int_map[i][n] == 0 || (int_map[i][n] != 0 && int_map[i][n] > l))
					int_map[i][n] = l;
				l++;
				n++;
			}
		}
		if (i < tmp->height)
		{
			n = j - 1;
			l = k;
			while (n >= 0)
			{
				if (int_map[i][n] == 0 || (int_map[i][n] != 0 && int_map[i][n] > l))
					int_map[i][n] = l;
				l++;
				n--;
			}
		}
		i++;
	}
	return (int_map);
}

void	ft_start_heat_map(t_map *tmp, int **int_map, int i, int j)
{
	int_map = ft_go_west(tmp, int_map, i, j - 1);
	int_map = ft_go_east(tmp, int_map, i, j + 1);
	int_map = ft_go_north(tmp, int_map, i - 1, j);
	int_map = ft_go_south(tmp, int_map, i + 1, j);
	//printf("%d\n", int_map[8][2]);
}
