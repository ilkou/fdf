/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 20:43:43 by mel-jadi          #+#    #+#             */
/*   Updated: 2019/02/25 23:35:34 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_creat_window(t_ptr *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx,
			p->ptr_map.img_width + 500, p->ptr_map.img_height, "fdf");
}

void	ft_creat_image(t_ptr *p)
{
	p->img = mlx_new_image(p->mlx, p->ptr_map.img_width, p->ptr_map.img_height);
	p->data = (int*)mlx_get_data_addr(p->img, p->bpp, p->size, p->endian);
}

void	ft_print_square(t_ptr *p)
{
	int		i;

	i = 0;
	while (i < p->ptr_map.img_width)
	{
		ft_mlx_putpixel(p, i, 0, 0x09EA1D);
		ft_mlx_putpixel(p, i, 1, 0x09EA1D);
		ft_mlx_putpixel(p, i, 2, 0x09EA1D);
		ft_mlx_putpixel(p, i, p->ptr_map.img_height, 0x09EA1D);
		ft_mlx_putpixel(p, i, p->ptr_map.img_height - 1, 0x09EA1D);
		ft_mlx_putpixel(p, i, p->ptr_map.img_height - 2, 0x09EA1D);
		i++;
	}
	i = 0;
	while (i < p->ptr_map.img_height)
	{
		ft_mlx_putpixel(p, 0, i, 0x09EA1D);
		ft_mlx_putpixel(p, 1, i, 0x09EA1D);
		ft_mlx_putpixel(p, 2, i, 0x09EA1D);
		ft_mlx_putpixel(p, p->ptr_map.img_width - 1, i, 0x09EA1D);
		ft_mlx_putpixel(p, p->ptr_map.img_width - 2, i, 0x09EA1D);
		ft_mlx_putpixel(p, p->ptr_map.img_width, i, 0x09EA1D);
		i++;
	}
}

void	ft_print_strigs(t_ptr *p)
{
	mlx_string_put(p->mlx, p->win,
			145, 5, 0xE11111, "1337 - projet FDF");
	mlx_string_put(p->mlx, p->win,
			50, 25, 0xE11111, "Realise par: <mel-jadi> && <oouklich>");
	mlx_string_put(p->mlx, p->win, 5, 70, 0xffde01, "Options :");
	mlx_string_put(p->mlx, p->win,
			5, 100, 0x09EA1D, "- Utilisez les boutons UP/DOWN/LEFT/RIGHT");
	mlx_string_put(p->mlx, p->win,
			5, 120, 0x09EA1D, "  pour se deplacer");
	mlx_string_put(p->mlx, p->win,
			5, 150, 0x09EA1D, "- Utilisez +/- pour zoomer avant/arrière");
	mlx_string_put(p->mlx, p->win,
			5, 180, 0x09EA1D, "- Utilisez w/z ou la molette de souris");
	mlx_string_put(p->mlx, p->win,
			5, 200, 0x09EA1D, "  pour changer l'altitude");
	mlx_string_put(p->mlx, p->win,
			5, 230, 0x09EA1D, "- Utilisez p/i pour changer la projection");
	mlx_string_put(p->mlx, p->win,
			5, 260, 0x09EA1D, "- Utilisez la bouton droite de souris");
	mlx_string_put(p->mlx, p->win,
			5, 280, 0x09EA1D, "  pour changer la position du map");
}
