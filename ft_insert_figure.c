/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_figure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:22:35 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/19 18:26:00 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	ft_write_figure(t_map *tmp, t_figure *fig)
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
				tmp->map[fig->best_i + a][fig->best_j + b] = tmp->order_char;
			b++;
		}
		b = 0;
		a++;
	}
}

int		ft_putfigure(int **int_map, t_figure *fig, int i, int j)
{
	int	a;
	int	b;
	int	sum;
	int	once;

	a = 0;
	b = 0;
	sum = 0;
	once = 0;
	while (a < fig->figure_a)
	{
		while (b < fig->figure_b)
		{
			if (int_map[i + a][j + b] != -2)
				sum += int_map[i + a][j + b];
			if (int_map[i + a][j + b] == -2 && fig->figure[a][b] == '*')
				once++;
			b++;
		}
		b = 0;
		a++;
	}
	//printf("sum %d %d : %d %d\n", sum , once, i, j);
	if (once != 1)
		return (-1);
	return (sum);
}

void	ft_insert_figure(t_map *tmp, t_figure *fig, int **int_map)
{
	int	i;
	int	j;
	int	sum;

	i = 0;
	j = 0;
	sum = 0;
	fig->best_sum = 1000;
	fig->best_i = 0;
	fig->best_j = 0;
	//printf("%d %d\n", fig->figure_a, fig->figure_b);
	//printf("%d %d\n", tmp->height, tmp->width);
	while (i < tmp->height - fig->figure_a)
	{
		while (j < tmp->width - fig->figure_b)
		{
			//if (int_map[i][j] == -2)
			{
				//printf("%d %d\n", i, j);
				sum = ft_putfigure(int_map, fig, i, j);
				//printf("%d\n", sum);
				if (fig->best_sum > sum && sum > 0)
				{
					fig->best_sum = sum;
					fig->best_i = i;
					fig->best_j = j;
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	//printf("sum = %d, i = %d, j = %d", fig->best_sum, fig->best_i, fig->best_j);
}
