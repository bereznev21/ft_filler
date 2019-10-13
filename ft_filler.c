/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:25:03 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/13 22:55:05 by rpoetess         ###   ########.fr       */
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

int		main(void)
{
	int			i;
	char		*line;
	t_map		*tmp;
	t_figure	*fig;
	int			**int_map;
	//char		*map;

	i = 1;
	//while (1)
	{
		tmp = (t_map*)malloc(sizeof(t_map));
		fig = (t_figure*)malloc(sizeof(t_figure));
	
		ft_srch_map(tmp);
		//if (i == 1)
		{
			ft_create_map(tmp);
			ft_write_map(tmp, line);
			ft_srch_figure(tmp, fig, line);
			int_map = ft_heatmap(int_map, tmp);
			ft_insert_figure(tmp, fig, int_map);
			ft_write_figure(tmp, fig);
			//ft_print_map(tmp);
			//if (ft_get_next_line(0, &line) == 1)
				//if (ft_strstr(line, "<got"))
			printf("%d %d\n", fig->best_i, fig->best_j);
			/*map = ft_strdup("");
			while (i == 1)
			{
				i = ft_get_next_line(0, &line);
				map = ft_strjoin_right(map, line);
				map = ft_strjoin_right(map, "\n");
				//printf("%s\n", line);
				if (i == 1)
					free(line);
			}
			printf("%s", map);
			free(map);*/
			ft_free_map(tmp);
			ft_strdel(fig->figure);
			free(fig);
		}
		//free(line);
	}
	return (0);
}
