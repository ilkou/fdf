/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometrie.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 20:32:52 by mel-jadi          #+#    #+#             */
/*   Updated: 2019/02/25 23:39:41 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_initia_b(t_ptr **p, t_coordn **map)
{
	*p = (struct s_ptr*)malloc(sizeof(struct s_ptr));
	(*p)->img = NULL;
	(*p)->mlx = NULL;
	(*p)->data = NULL;
	(*p)->win = NULL;
	(*p)->bpp = malloc(4);
	(*p)->size = malloc(4);
	(*p)->endian = malloc(4);
	(*p)->proj_type = 0;
	(*p)->ptr_map.map = map;
	(*p)->ptr_map.map_width = get_width(map);
	(*p)->ptr_map.map_height = get_height(map);
}

void	ft_initia_a(t_ptr **p, t_coordn **map)
{
	ft_initia_b(p, map);
	if (((*p)->ptr_map.img_height = (int)log((double)((*p)->ptr_map.map_width *
						(*p)->ptr_map.map_height)) * 150.0) > 1310)
	{
		if ((*p)->ptr_map.img_height > 2020)
			(*p)->ptr_map.img_width = 2020;
		else
			(*p)->ptr_map.img_width = (*p)->ptr_map.img_height;
		(*p)->ptr_map.img_height = 1310;
	}
	else
		(*p)->ptr_map.img_width = (*p)->ptr_map.img_height;
	(*p)->ptr_map.max_z = get_max_z(map);
	if ((*p)->ptr_map.map_height > (*p)->ptr_map.map_width)
		(*p)->zoom = (double)((*p)->ptr_map.img_width
				/ (*p)->ptr_map.map_height) / 25;
	else
		(*p)->zoom = (double)((*p)->ptr_map.img_width
				/ (*p)->ptr_map.map_width) / 25;
	(*p)->u = ft_point(0, (*p)->ptr_map.max_z * (*p)->zoom * 2.5, 0);
}

void	**ft_caval(t_coordn **map, double zoom, t_point u)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j].x != -2147483648)
		{
			map[i][j].x = zoom * ((double)j * 20 +
					0.7 * cos(45) * (double)i * 20 + u.x);
			map[i][j].y = zoom * (-(map[i][j].z == 0 ? map[i][j].z *
						2.5 : map[i][j].z * 2.5 + u.z) + 0.7
					* sin(45) * (double)i * 20 + u.y);
			j++;
		}
		i++;
	}
	return ((void**)map);
}

void	**ft_iso(t_coordn **map, double zoom, t_point u)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j].x != -2147483648)
		{
			map[i][j].x = zoom * (sqrt(2.0) / 2) * ((double)j *
					20 - (double)i * 20 + u.x);
			map[i][j].y = zoom * ((1 / sqrt(6.0)) * ((double)j * 20 +
						(double)i * 20) - sqrt(2.0 / 3.0) * (map[i][j].z == 0 ?
							map[i][j].z * 2.5 : map[i][j].z * 2.5 + u.z) + u.y);
			j++;
		}
		i++;
	}
	return ((void**)map);
}
