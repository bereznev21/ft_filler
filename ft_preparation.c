/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preparation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:05:14 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/11 17:05:39 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

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

void	ft_srch_order(char *line, t_map *tmp)
{
	if (ft_strstr(line, "$$$ exec p1 : [players/abanlin.filler]"))
		tmp->order = 1;
	else
		tmp->order = 2;
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
	//printf("|%d %d|", tmp->height, tmp->width);
	free(a);
	free(b);
	free(line);
}
