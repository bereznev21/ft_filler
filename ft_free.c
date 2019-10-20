#include "ft_filler.h"

void	ft_free_char(char **map, int width)
{
	int	i;

	i = 0;
	while (i < width)
		free(map[i++]);
	free(map);
}

void	ft_free_int(int **map, int width)
{
	int	i;

	i = 0;
	while (i < width)
		free(map[i++]);
	free(map);
}

void	ft_free(t_map *tmp, t_figure *fig)
{
	ft_free_char(tmp->map, tmp->height);
	ft_free_char(fig->figure, fig->figure_a);
	free(fig);
	free(tmp);
}

