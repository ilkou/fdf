/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:41:48 by mel-jadi          #+#    #+#             */
/*   Updated: 2019/02/25 20:58:43 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_linelen(char **str)
{
	int			ln;

	ln = 0;
	while (str[ln])
		ln++;
	return (ln);
}

int			ft_nbr_line(char *file)
{
	char		*line;
	int			fd;
	int			nbr_line;

	nbr_line = 1;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		nbr_line++;
	}
	close(fd);
	return (nbr_line);
}

void		ft_free_it(void **free_it)
{
	int			i;

	i = 0;
	while (free_it[i])
	{
		free(free_it[i]);
		i++;
	}
	free(free_it);
}

t_coordn	**ft_get_coordn(char *file, int fd)
{
	char		*line;
	t_coordn	**map;
	char		**dest;
	int			i;
	int			j;

	i = 0;
	map = (struct s_coordn**)malloc(sizeof(struct s_coordn) *
			(ft_nbr_line(file) == 1 ? error(2) : ft_nbr_line(file)));
	while (get_next_line(fd, &line) > 0)
	{
		dest = ft_strsplit(line, ' ');
		map[i++] = (struct s_coordn*)
			malloc(sizeof(struct s_coordn) * (ft_linelen(dest) + 1));
		j = -1;
		while (++j < ft_linelen(dest))
			map[i - 1][j].z = (double)(ft_atoi(dest[j]));
		map[i - 1][j].x = -2147483648;
		(ft_linelen(dest) != get_width(map)) ? error(0) : error(1337);
		free(line);
		ft_free_it((void**)dest);
	}
	map[i] = 0;
	return (map);
}
