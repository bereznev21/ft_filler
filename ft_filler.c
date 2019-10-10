/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:25:03 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/10 23:38:05 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"
#include <stdio.h>

int		ft_check_space(int x, int y)
{
	if (x == 3 && y == 4)
	{
		printf("X");
		return (1);
	}
	return (0);
}

void	ft_write_map(int height, int width)
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

void	ft_srch_order(char *line, t_map *tmp)
{
	if (ft_strstr(line, "$$$ exec p1 : [players/abanlin.filler]"))
		tmp->pos = 1;
	else
		tmp->pos = 2;
	free(line);
	//printf("%d\n", tmp->pos);
}

void	ft_srch_size(char *line, t_map *tmp)
{
	int		i;
	char	*a;
	char	*b;

	i = 8;
	a = ft_strdup("");
	b = ft_strdup("");
	while (line[i] != ' ')
		a = ft_strjoin_char(a, line[i++]);
	i++;
	while (line[i] != ':')
		b = ft_strjoin_char(b, line[i++]);
	tmp->height = ft_atoi(a);
	tmp->width = ft_atoi(b);
	//printf("%s\n", &line[8]);
	free(a);
	free(b);
	free(line);
}

void	ft_srch_map(t_map *tmp)
{
	int		num_line;
	int		i;
	char	*line;

	i = 1;
	num_line = 0;
	while (num_line < 6 && i == 1)
	{
		i = ft_get_next_line(0, &line);
		num_line++;
		free(line);
	}
	if (ft_get_next_line(0, &line) == 1)
		ft_srch_order(line, tmp);
	while (num_line < 8 && i == 1)
	{
		i = ft_get_next_line(0, &line);
		num_line++;
		free(line);
	}
	if (ft_get_next_line(0, &line) == 1)
		ft_srch_size(line, tmp);
}

char	**create_map(int i, int j)
{
	int		index;
	char	**arr;

	index = 0;
	arr = (char**)malloc(j * sizeof(char*));
	while (index < i)
		arr[index++] = (char*)malloc(i * sizeof(char));
	return (arr);
}

void	ft_srch_pos(t_map *tmp, char *line)
{
	int	i;
	int	j;

	j = 0;
	i = ft_get_next_line(0, &line);
	free(line);
	while (i == 1 && j < tmp->height)
	{
		ft_putnbr(j);
		i = ft_get_next_line(0, &line);
		tmp->map[j] = ft_strjoin_right(tmp->map[j], &line[4]);
		j++;
	}
}

int		main(void)
{
	int		i;
	t_map	*tmp;
	char	*line;
	char	*map;

	i = 1;
	ft_srch_map(tmp);
	tmp->map = create_map(tmp->height, tmp->width);
	ft_srch_pos(tmp, line);
	map = ft_strdup("");
	while (i == 1)
	{
		i = ft_get_next_line(0, &line);
		map = ft_strjoin_right(map, line);
		map = ft_strjoin_right(map, "\n");
		//printf("%s\n", line);
		//free(line);
	}
	printf("%s", map);
	free(map);
	return (0);
}
