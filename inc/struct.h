/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:16:43 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/20 17:32:35 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_dir_double
{
	double	x;
	double	y;
}	t_dir_d;

typedef struct s_dir_int
{
	int	x;
	int	y;
}	t_dir_int;

typedef struct s_img
{
	void	*img;
	int		*adr;
	int		px_bits;
	int		size_line;
	int		endian;
	int		h;
	int		w;
}	t_img;

typedef struct s_tex
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	unsigned long	hex_f;
	unsigned long	hex_c;
	t_dir_int		dir;
}	t_tex;

typedef struct s_framebuffer
{
	t_img		*img;
	t_dir_int	offset;
	int			view_dist;
	int			tile_size;
	int			size;
	char		**map;
}	t_framebuffer;

typedef struct s_map
{
	int			eom;
	int			line;
	int			h;
	int			w;
	int			fd;
	char		**file;
	char		*path;
}	t_map;

typedef struct s_ray
{
	t_dir_int	map;
	t_dir_int	step;
	t_dir_d		dir;
	t_dir_d		side_dist;
	t_dir_d		delta_dist;
	double		cam_x;
	double		wall_x;
	double		wall_dist;
	int			side;
	int			line_h;
	int			start;
	int			end;
}	t_ray;

typedef struct s_player
{
	t_dir_int	move;
	t_dir_d		plane;
	t_dir_d		pos;
	t_dir_d		dir_t;
	char		dir;
	int			moved;
	int			rotate;
}	t_player;

typedef struct s_game
{
	t_map			map_info;
	t_tex			tex_info;
	t_img			framebuffer;
	t_player		player;
	t_ray			ray;
	double			time;
	int				win_h;
	int				win_w;
	char			**map;
	char			**cub_file;
	void			*mlx;
	void			*win;
	int				**tex_px;
	int				**tex;
}	t_game;

#endif
