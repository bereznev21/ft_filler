/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_figure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:22:35 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/21 22:07:59 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void		ft_write_figure(t_map *tmp, t_figure *fig)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < fig->figure_a)
	{
		while (b < fig->figure_b)
		{
			if (fig->figure[a][b] == '*')
				tmp->map[fig->best_i + a][fig->best_j + b] = 'X';
			b++;
		}
		b = 0;
		a++;
	}
}

int			ft_putfigure1(t_map *tmp,
					int **int_map, t_figure *fig, uintmax_t *sum)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	tmp->once = 0;
	while (a < fig->figure_a)
	{
		while (b < fig->figure_b)
		{
			if (fig->figure[a][b] == '*'
			&& int_map[tmp->tmp_i + a][tmp->tmp_j + b] == tmp->his_order)
				return (-1);
			if (int_map[tmp->tmp_i + a][tmp->tmp_j + b] > 0
			&& fig->figure[a][b] == '*')
				*sum += int_map[tmp->tmp_i + a][tmp->tmp_j + b];
			if (fig->figure[a][b] == '*'
			&& int_map[tmp->tmp_i + a][tmp->tmp_j + b] == tmp->my_order)
				tmp->once++;
			b++;
		}
		b = 0;
		a++;
	}
	return (tmp->once);
}

uintmax_t	ft_putfigure(t_map *tmp, int **int_map, t_figure *fig)
{
	uintmax_t	sum;

	sum = 0;
	if (ft_putfigure1(tmp, int_map, fig, &sum) != 1)
		return (-1);
	return (sum);
}

void		ft_insert_figure(t_map *tmp, t_figure *fig, int **int_map)
{
	uintmax_t	sum;

	tmp->tmp_i = 0;
	tmp->tmp_j = 0;
	sum = 0;
	while (tmp->tmp_i <= tmp->height - fig->figure_a)
	{
		while (tmp->tmp_j <= tmp->width - fig->figure_b)
		{
			{
				sum = ft_putfigure(tmp, int_map, fig);
				if ((fig->best_sum > sum || fig->best_sum == 0) && sum > 0)
				{
					fig->best_sum = sum;
					fig->best_i = tmp->tmp_i;
					fig->best_j = tmp->tmp_j;
				}
			}
			tmp->tmp_j++;
		}
		tmp->tmp_j = 0;
		tmp->tmp_i++;
	}
}
