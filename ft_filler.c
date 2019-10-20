/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:25:03 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/20 23:15:46 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		ft_read_header(char *line, int num)
{
	int	i;

	i = 0;
	ft_get_next_line(0, &line);
	if (ft_strstr(line, "launched") && num == 0)
	{
		free(line);
		ft_get_next_line(0, &line);
		if (ft_strstr(line, "rpoetess") && ft_strstr(line, "p1"))
			num = -1;
		else if (ft_strstr(line, "p1"))
			num = -2;
		free(line);
		while (i++ < 2)
		{
			ft_get_next_line(0, &line);
			free(line);
		}
		return (num);
	}
	return (0);
}

void	ft_init_struct(t_map *tmp, t_figure *fig)
{
	tmp->height = 0;
	tmp->width = 0;
	fig->figure = NULL;
	fig->best_i = 0;
	fig->best_j = 0;
	fig->best_sum = 1000;
}

int		ft_go(t_map *tmp, t_figure *fig, char *line)
{
	while (1)
	{
		if (ft_get_next_line(0, &line) == 0)
			return (0);
		if (ft_strstr(line, "Plateau "))
		{
			ft_srch_size(line, tmp);
			ft_write_map(tmp, line);
		}
		else if (ft_strstr(line, "Piece "))
		{
			ft_srch_figure_size(fig, line);
			ft_srch_figure(fig, line);
			return (1);
		}
		else
			free(line);
	}
	return (1);
}

void	ft_print_res(t_figure *fig)
{
	ft_putnbr(fig->best_i);
	ft_putchar(' ');
	ft_putnbr(fig->best_j);
	ft_putchar('\n');
}

int		main(void)
{
	int			num;
	char		*line;
	t_map		*tmp;
	t_figure	*fig;
	int			**int_map;

	line = NULL;
	num = 0;
	num = ft_read_header(line, num);
	if (num == 0)
		num = -2;
	while (1)
	{
		tmp = (t_map*)malloc(sizeof(t_map));
		fig = (t_figure*)malloc(sizeof(t_figure));
		int_map = 0;
		tmp->my_order = num;
		tmp->his_order = (tmp->my_order == -1) ? -2 : -1;
		/*if (tmp->my_order == -1)
			tmp->his_order = -2;
		else
			tmp->his_order = -1;*/
		//printf("%d %d\n", tmp->my_order, tmp->his_order);
		ft_init_struct(tmp, fig);
		if (ft_go(tmp, fig, line) == 0)
		{
			//printf("%d %d\n", tmp->my_order, tmp->his_order);
			free(tmp);
			free(fig);
			return (0);
		}
		int_map = ft_heatmap(int_map, tmp);
		ft_insert_figure(tmp, fig, int_map);
		ft_write_figure(tmp, fig);
		//ft_print_map(tmp);
		ft_print_res(fig);
		/*ft_putnbr(tmp->my_order);
		ft_putchar(' ');
		ft_putnbr(tmp->his_order);
		ft_putchar('\n');*/
		ft_free_int(int_map, tmp->height);
		ft_free(tmp, fig);
	}
	return (0);
}
