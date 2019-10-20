/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preparation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:05:14 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/20 17:40:03 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

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
	ft_create_map(tmp);
	free(a);
	free(b);
	free(line);
}
