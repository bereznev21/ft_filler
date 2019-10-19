/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preparation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:05:14 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/19 18:20:39 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		ft_srch_map(t_map *tmp)
{
	int		num_line;
	int		i;
	char	*line;

	i = 0;
	num_line = 0;
	//while (i == 0)
	{
		//ft_putchar('!');
		//ft_putchar('!');
		i = ft_get_next_line(0, &line);
	}
	if (ft_strstr(line, "VM  version 1.1"))
	{
		while (num_line < 5 && i == 1)
		{
			i = ft_get_next_line(0, &line);
			num_line++;
			if (i == 1)
				free(line);
		}
		num_line = 0;
	}
	//if (ft_get_next_line(0, &line) == 1)
	ft_srch_order(line, tmp);
	i = ft_get_next_line(0, &line);
	//free (line);
	while (num_line < 2 && i == 1)
	{
		i = ft_get_next_line(0, &line);
		num_line++;
		if (i == 1)
			free(line);
	}
	if (ft_get_next_line(0, &line) == 1)
		ft_srch_size(line, tmp);
	return (i);
}

void	ft_srch_order(char *line, t_map *tmp)
{
	if (ft_strstr(line, "launched /players/rpoetess.filler"))
	{
		tmp->order_char = 'X';
		tmp->order = 1;
	}
	else
	{
		tmp->order_char = 'O';
		tmp->order = 2;
	}
	//free(line);
	//printf("%d\n", tmp->order);
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
	ft_create_map(tmp);
	free(a);
	free(b);
	free(line);
}
