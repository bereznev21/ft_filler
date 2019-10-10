/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:15:05 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/10 21:18:16 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft/includes/libft.h"

//int	get_next_line(const int fd, char **line);
typedef struct		s_map
{
	int		height;
	int		width;
	int		pos;
	char	**map;
}					t_map;
#endif
