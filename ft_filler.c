/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:25:03 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/11 23:00:02 by rpoetess         ###   ########.fr       */
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
	printf("    ");
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

int		main(void)
{
	int			i;
	char		*line;
	t_map		*tmp;
	t_figure	*fig;
	//char		*map;

	i = 1;
	tmp = (t_map*)malloc(sizeof(t_map));
	fig = (t_figure*)malloc(sizeof(t_figure));
	ft_srch_map(tmp);
	ft_create_map(tmp);
	ft_write_map(tmp, line);
	ft_srch_figure(tmp, fig, line);
	//printf("%c\n", tmp->map[0][0]);
	ft_heatmap(tmp);
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
	//free(line);
	return (0);
}
