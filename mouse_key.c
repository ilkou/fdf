/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:28:02 by mel-jadi          #+#    #+#             */
/*   Updated: 2019/02/26 00:27:32 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_switch_proj(int key, t_ptr *p)
{
	if (key == MLX_KEY_PAD_P)
		p->proj_type = 1;
	else if (key == MLX_KEY_PAD_I)
		p->proj_type = 0;
}

void	ft_move(int key, t_ptr *p)
{
	if (key == MLX_KEY_PAD_RIGHT)
		p->u.x += 45.0;
	else if (key == MLX_KEY_PAD_LEFT)
		p->u.x -= 45.0;
	else if (key == MLX_KEY_PAD_DOWN)
		p->u.y += 45.0;
	else if (key == MLX_KEY_PAD_UP)
		p->u.y -= 45.0;
	else if (key == MLX_KEY_PAD_PLUS)
		p->zoom += 0.05;
	else if (key == MLX_KEY_PAD_MINUS)
		p->zoom -= 0.05;
	else if (key == MLX_KEY_PAD_W)
		p->u.z += 2.5;
	else if (key == MLX_KEY_PAD_Z)
		p->u.z -= 2.5;
}

int		ft_deal_key(int key, t_ptr *p)
{
	if (key == MLX_KEY_PAD_ESC)
	{
		mlx_destroy_image(p->mlx, p->img);
		mlx_destroy_window(p->mlx, p->win);
		ft_free_it((void**)p->ptr_map.map);
		free(p);
		exit(0);
	}
	ft_switch_proj(key, p);
	ft_move(key, p);
	ft_draw(p);
	return (key);
}

int		ft_mouse_press(int button, int x, int y, t_ptr *p)
{
	x = y;
	if (button == 4)
		p->u.z += 10;
	else if (button == 5)
		p->u.z -= 10;
	ft_draw(p);
	return (button);
}

int		ft_mouse_release(int button, int x, int y, t_ptr *p)
{
	p->u.x = (int)((x - 500) / p->zoom);
	p->u.y = (int)(y / p->zoom);
	ft_draw(p);
	return (button);
}
