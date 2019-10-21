/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_figure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:22:35 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/21 18:04:38 by rpoetess         ###   ########.fr       */
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

uintmax_t	ft_putfigure(t_map *tmp, int **int_map, t_figure *fig, int i, int j)
{
	int			a;
	int			b;
	uintmax_t	sum;
	int			once;

	a = 0;
	b = 0;
	sum = 0;
	once = 0;
	//printf("%d %d\n", tmp->my_order, tmp->his_order);
	while (a < fig->figure_a)
	{
		while (b < fig->figure_b)
		{
			if (fig->figure[a][b] == '*' && int_map[i + a][j + b] == tmp->his_order)
				return (-1);
			if (int_map[i + a][j + b] > 0 && fig->figure[a][b] == '*')
				sum += int_map[i + a][j + b];
			if (fig->figure[a][b] == '*' && int_map[i + a][j + b] == tmp->my_order)
				once++;
			b++;
		}
		b = 0;
		a++;
	}
	/*
	ft_putnbr(fig->best_i);
	ft_putchar(' ');
	ft_putnbr(fig->best_j);
	ft_putchar('\n');
	*/
	//printf("sum %d %d : %d %d\n", sum , once, i, j);
	if (once != 1)
		return (-1);
	return (sum);
}

void	ft_insert_figure(t_map *tmp, t_figure *fig, int **int_map)
{
	int			i;
	int			j;
	uintmax_t	sum;

	i = 0;
	j = 0;
	sum = 0;
	fig->best_sum = 0;
	fig->best_i = 0;
	fig->best_j = 0;
	while (i <= tmp->height - fig->figure_a)
	{
		while (j <= tmp->width - fig->figure_b)
		{
			{
				sum = ft_putfigure(tmp, int_map, fig, i, j);
				if ((fig->best_sum > sum || fig->best_sum == 0) && sum > 0)
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
