/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 21:32:10 by oouklich          #+#    #+#             */
/*   Updated: 2019/02/25 23:57:49 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_putpixel(t_ptr *p, int x, int y, int color)
{
	if (x >= 0 && x < p->ptr_map.img_width
			&& y >= 0 && y < p->ptr_map.img_height)
	{
		p->data[y * p->ptr_map.img_width + x] = color;
	}
}

void	ft_write_img(t_ptr *p, t_coordn **map)
{
	int			i;
	int			j;

	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j].x != -2147483648)
		{
			if (map[i][j + 1].x != -2147483648)
				ft_draw_line(map[i][j], map[i][j + 1], p);
			if (map[i + 1])
				ft_draw_line(map[i + 1][j], map[i][j], p);
			j++;
		}
		i++;
	}
}

int		ft_draw(t_ptr *p)
{
	ft_bzero(p->data, p->ptr_map.img_width * p->ptr_map.img_height * 4);
	p->proj_type == 1 ?
		ft_write_img(p, (t_coordn**)ft_iso(p->ptr_map.map, p->zoom, p->u))
		: ft_write_img(p, (t_coordn**)ft_caval(p->ptr_map.map, p->zoom, p->u));
	ft_print_square(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 500, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_coordn	**map;
	t_ptr		*p;
	int			fd;

	if (argc != 2)
		error(1);
	fd = open(argv[1], O_RDONLY);
	map = ft_get_coordn(argv[1], fd);
	close(fd);
	ft_initia_a(&p, map);
	ft_creat_window(p);
	ft_creat_image(p);
	ft_print_strigs(p);
	ft_draw(p);
	mlx_hook(p->win, 2, 0, ft_deal_key, p);
	mlx_hook(p->win, 4, 0, ft_mouse_press, p);
	mlx_hook(p->win, 5, 0, ft_mouse_release, p);
	mlx_loop(p->mlx);
	return (0);
}
