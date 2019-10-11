/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srch_figure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:51:14 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/11 21:58:44 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	ft_crt_figure(t_figure *fig)
{
	int	index;

	index = 0;
	//printf("|%d %d\n|", tmp->figure_a, tmp->figure_b);
	fig->figure = (char**)malloc(sizeof(char*) * (fig->figure_a));
	while (index < fig->figure_a)
		fig->figure[index++] = (char*)malloc(sizeof(char) * (fig->figure_b));
}

void	ft_srch_figure_size(t_figure *fig, char *line)
{
	int		j;
	char	*a;
	char	*b;

	j = 6;
	a = ft_strdup("");
	b = ft_strdup("");
	while (line[j] != ' ')
		a = ft_strjoin_char(a, line[j++]);
	j++;
	while (line[j] != ':')
		b = ft_strjoin_char(b, line[j++]);
	fig->figure_a = atoi(a);
	fig->figure_b = atoi(b);
	ft_crt_figure(fig);
	free(a);
	free(b);
	//free(line);
}

void	ft_srch_figure(t_map *tmp, t_figure *fig, char *line)
{
	int	i;
	int index;

	i = 1;
	index = 0;
	while (i == 1)
	{
		i = ft_get_next_line(0, &line);
		if (ft_strstr(line, "Piece "))
			ft_srch_figure_size(fig, line);
		if (ft_strstr(line, ".") || ft_strstr(line, "*"))
		{
			//printf("%s\n", line);
			fig->figure[index] = ft_strjoin_right(fig->figure[index], line);
			index++;
		}
		(i == 1) ? free(line) : 0;
	}
}
