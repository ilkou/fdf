/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 20:20:50 by mel-jadi          #+#    #+#             */
/*   Updated: 2019/02/25 22:26:27 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point			ft_point(int x, int y, int z)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

unsigned long	error(int a)
{
	if (a == 1)
	{
		ft_putstr("usage: ./fdf file.fdf\n");
		exit(0);
	}
	else if (a == 0)
	{
		ft_putstr("Found wrong line length. Exiting.\n");
		exit(0);
	}
	else if (a == 2)
	{
		ft_putstr("error\n");
		exit(0);
	}
	return (0);
}

int				get_width(t_coordn **map)
{
	int		i;

	i = 0;
	while (map[0][i].x != -2147483648)
		i++;
	return (i);
}

int				get_height(t_coordn **map)
{
	int		i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int				get_max_z(t_coordn **map)
{
	int		i;
	int		j;
	int		max;

	i = 0;
	max = 0;
	while (map[i])
	{
		j = -1;
		while (map[i][++j].x != -2147483648)
			max = map[i][j].z > max ? map[i][j].z : max;
		i++;
	}
	return (max);
}
