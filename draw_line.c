/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:03:04 by mel-jadi          #+#    #+#             */
/*   Updated: 2019/02/26 00:12:52 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_coloration(t_coordn p1, t_coordn p2, t_ptr *p)
{
	if (p1.z == 0 && p2.z == 0)
		return (0x8DA100);
	else if (p1.z == p->ptr_map.max_z && p2.z == p->ptr_map.max_z)
		return (0xFFFFFF);
	else if ((p1.z < 0 && p2.z == 0) || (p2.z < 0 && p1.z == 0))
		return (0x1966FF);
	else if (p1.z < 0 && p2.z < 0)
		return (0x1966FF + (p1.z > p2.z ? p2.z + 2 : p1.z + 2));
	else if ((p1.z > 0 && p2.z == 0) || (p2.z > 0 && p1.z == 0))
		return (0xB37700 + (p1.z > p2.z ? p2.z + 10 : p1.z + 10));
	else if ((p1.z > 0 && p2.z != 0) || (p2.z > 0 && p1.z != 0))
		return (0xFFAA00 + (p1.z > p2.z ? p1.z + 10 : p2.z + 10));
	return (0xFFFFFF);
}

void	ft_draw_horiz(t_line *l, t_coordn p1, t_coordn p2, t_ptr *p)
{
	l->cumul = l->dx / 2;
	l->i = 0;
	while (++l->i <= l->dx)
	{
		l->x += l->xinc;
		l->cumul += l->dy;
		if (l->cumul >= l->dx)
		{
			l->cumul -= l->dx;
			l->y += l->yinc;
		}
		ft_mlx_putpixel(p, l->x, l->y, ft_coloration(p1, p2, p));
	}
}

void	ft_draw_verti(t_line *l, t_coordn p1, t_coordn p2, t_ptr *p)
{
	l->cumul = l->dy / 2;
	l->i = 0;
	while (++l->i <= l->dy)
	{
		l->y += l->yinc;
		l->cumul += l->dx;
		if (l->cumul >= l->dy)
		{
			l->cumul -= l->dy;
			l->x += l->xinc;
		}
		ft_mlx_putpixel(p, l->x, l->y, ft_coloration(p1, p2, p));
	}
}

void	ft_draw_line(t_coordn p1, t_coordn p2, t_ptr *p)
{
	t_line	*l;

	l = (struct s_line *)malloc(sizeof(struct s_line));
	l->x = p1.x;
	l->y = p1.y;
	l->dx = p2.x - p1.x;
	l->dy = p2.y - p1.y;
	l->xinc = (l->dx > 0) ? 1 : -1;
	l->yinc = (l->dy > 0) ? 1 : -1;
	l->dx = abs(l->dx);
	l->dy = abs(l->dy);
	ft_mlx_putpixel(p, l->x, l->y, ft_coloration(p1, p2, p));
	if (l->dx > l->dy)
		ft_draw_horiz(l, p1, p2, p);
	else
		ft_draw_verti(l, p1, p2, p);
	free(l);
}
