/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crt_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:50:56 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/21 22:23:12 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	ft_create_map(t_map *tmp)
{
	int		index;

	index = 0;
	if (!(tmp->map = (char**)malloc(sizeof(char*) * (tmp->height))))
		return ;
	while (index < tmp->height)
	{
		if (!(tmp->map[index] = (char*)malloc(sizeof(char) * (tmp->width))))
			return ;
		index++;
	}
}

void	ft_free_map(int **tmp, int width)
{
	int	i;

	i = 0;
	while (i < width)
		free(tmp[i++]);
	free(tmp);
}

void	ft_write_map(t_map *tmp, char *line)
{
	int	j;

	ft_get_next_line(0, &line);
	free(line);
	j = 0;
	while (j < tmp->height)
	{
		ft_get_next_line(0, &line);
		tmp->map[j] = ft_strjoin_right(tmp->map[j], &line[4]);
		free(line);
		j++;
	}
}
