/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srch_figure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:51:14 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/19 17:45:49 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	ft_crt_figure(t_figure *fig)
{
	int	index;

	index = 0;
	//printf("|%d %d|\n", fig->figure_a, fig->figure_b);
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
	fig->figure_a = 0;
	fig->figure_b = 0;
	while (line[j] != ' ')
	{
		a = ft_strjoin_char(a, line[j]);
		j++;
	}
	while (line[j] != ':')
	{
		b = ft_strjoin_char(b, line[j]);
		j++;
	}
	fig->figure_a = ft_atoi(a);
	fig->figure_b = ft_atoi(b);
	ft_crt_figure(fig);
	free(a);
	free(b);
	free(line);
}

void	ft_srch_figure(t_figure *fig, char *line)
{
	int	i;

	i = 0;
	//printf("%d\n", fig->figure_a);
	while (i < fig->figure_a)
	{
		ft_get_next_line(0, &line);
		fig->figure[i] = ft_strjoin_right(fig->figure[i], line);
		//printf("%s\n", fig->figure[i]);
		i++;
		free(line);
	}
}
