/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:25:03 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/19 18:32:57 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		ft_check_space(int x, int y)
{
	if (x == 3 && y == 4)
	{
		printf("X");
		return (1);
	}
	return (0);
}

void	ft_write_map2(int height, int width)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (b < width)
		printf("%d", b++ % 10);
	printf("\n");
	b = 0;
	while (a < height)
	{
		printf("%03d ", a);
		while (b < width)
		{
			ft_check_space(a, b) ? 0 : printf(".");
			b++;
		}
		printf("\n");
		b = 0;
		a++;
	}
}

void	ft_print_map(t_map *tmp)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	printf("    ");
	while (b < tmp->width)
		printf("%d", b++ % 10);
	printf("\n");
	b = 0;
	while (a < tmp->height)
	{
		printf("%03d ", a);
		while (b < tmp->width)
		{
			printf("%c", tmp->map[a][b]);
			b++;
		}
		printf("\n");
		b = 0;
		a++;
	}
}

void	ft_read_header(char *line, int num, char order)
{
	int	i;

	i = 0;
	ft_get_next_line(0, &line);
	if (ft_strstr(line, "VM  version 1.1"))
	{
		while (i++ < 5)
			ft_get_next_line(0, &line);
		i = 0;
	}
	if (ft_strstr(line, "p1 : [players/rpoetess.filler]"))
	{
		order = 'O';
		num = -1;
		free(line);
	}
	else if (ft_strstr(line, "launched"))
	{
		order = 'X';
		num = -2;
		free(line);
	}
	while (i++ < 3)
	{
		ft_get_next_line(0, &line);
		free(line);
	}
}

void	ft_init_struct(t_map *tmp, t_figure *fig)
{
	//tmp = NULL;
	tmp->height = 0;
	tmp->width = 0;
	//tmp->map = NULL;
	fig->best_i = 0;
	fig->best_j = 0;
	//fig->best_sum = 1000;
	fig = 0;
}

int		main(void)
{
	int			num;
	char		order;
	char		*line;
	t_map		*tmp;
	t_figure	*fig;
	int			**int_map;

	num = 0;
	order = 'X';
	line = NULL;
	ft_read_header(line, num, order);
	while (1)
	{
		tmp = (t_map*)malloc(sizeof(t_map));
		fig = (t_figure*)malloc(sizeof(t_figure));
		int_map = 0;
		tmp->order = num;
		tmp->order_char = order;
		ft_init_struct(tmp, fig);
		while (1)
		{
			if (ft_get_next_line(0, &line) == 0)
				return (0);
			if (ft_strstr(line, "Plateau "))
			{
				//ft_putstr(line);
				//ft_putchar('\n');
				ft_srch_size(line, tmp);
				ft_write_map(tmp, line);
			}
			else if (ft_strstr(line, "Piece "))
			{
				ft_srch_figure_size(fig, line);
				ft_srch_figure(fig, line);
				//return (1);
				break ;
			}
			//else
			//	free(line);
		}

		int_map = ft_heatmap(int_map, tmp);
		ft_insert_figure(tmp, fig, int_map);
		//ft_write_figure(tmp, fig);
		//ft_print_map(tmp);
		
		{
			ft_putnbr(fig->best_i);
			ft_putchar(' ');
			ft_putnbr(fig->best_j);
			ft_putchar('\n');
		}
		//ft_putstr("11 14\n");
		//ft_strdel(tmp->map);
		free(tmp);
		ft_strdel(fig->figure);
		free(fig);
		free(int_map);
		
	}
	//free(line);
	return (0);
}
