/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 21:32:28 by oouklich          #+#    #+#             */
/*   Updated: 2019/02/26 00:16:45 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define MLX_KEY_PAD_MINUS 78
# define MLX_KEY_PAD_PLUS 69
# define MLX_KEY_PAD_LEFT 123
# define MLX_KEY_PAD_RIGHT 124
# define MLX_KEY_PAD_UP 126
# define MLX_KEY_PAD_DOWN 125
# define MLX_KEY_PAD_P 34
# define MLX_KEY_PAD_I 35
# define MLX_KEY_PAD_W 13
# define MLX_KEY_PAD_Z 6
# define MLX_KEY_PAD_ESC 53

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			i;
	int			xinc;
	int			yinc;
	int			cumul;
	int			x;
	int			y;
}				t_line;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_coordn
{
	double		x;
	double		y;
	double		z;
}				t_coordn;

typedef struct	s_map
{
	int			map_width;
	int			map_height;
	int			img_width;
	int			img_height;
	int			max_z;
	t_coordn	**map;
}				t_map;

typedef struct	s_ptr
{
	void		*win;
	void		*mlx;
	void		*img;
	int			*data;
	int			*bpp;
	int			*size;
	int			*endian;
	double		zoom;
	int			proj_type;
	t_point		u;
	t_map		ptr_map;
}				t_ptr;

void			ft_draw_line(t_coordn p1, t_coordn p2, t_ptr *p);
void			ft_draw_verti(t_line *l, t_coordn p1, t_coordn p2, t_ptr *p);
void			ft_draw_horiz(t_line *l, t_coordn p1, t_coordn p2, t_ptr *p);
void			ft_mlx_putpixel(t_ptr *p, int x, int y, int color);
int				ft_coloration(t_coordn p1, t_coordn p2, t_ptr *p);
int				ft_mouse_release(int button, int x, int y, t_ptr *p);
int				ft_mouse_press(int button, int x, int y, t_ptr *p);
int				ft_deal_key(int key, t_ptr *p);
void			ft_move(int key, t_ptr *p);
void			ft_switch_proj(int key, t_ptr *p);
int				ft_draw(t_ptr *p);
t_coordn		**ft_get_coordn(char *file, int fd);
int				ft_nbr_line(char *file);
int				ft_linelen(char **str);
int				get_width(t_coordn **map);
int				get_height(t_coordn **map);
unsigned long	error(int a);
void			ft_free_it(void **free_it);
int				get_max_z(t_coordn **map);
t_point			ft_point(int x, int y, int z);
void			**ft_caval(t_coordn **map, double zoom, t_point u);
void			**ft_iso(t_coordn **map, double zoom, t_point u);
void			ft_initia_a(t_ptr **p, t_coordn **map);
void			ft_initia_b(t_ptr **p, t_coordn **map);
void			ft_creat_window(t_ptr *p);
void			ft_creat_image(t_ptr *p);
void			ft_print_square(t_ptr *p);
void			ft_print_strigs(t_ptr *p);
void			ft_mlx_putpixel(t_ptr *p, int x, int y, int color);
void			ft_write_img(t_ptr *p, t_coordn **map);
int				ft_draw(t_ptr *p);
#endif
