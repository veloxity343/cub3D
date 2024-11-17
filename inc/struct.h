/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:14:33 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/15 14:42:01 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_texture
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}					t_texture;

typedef struct s_map
{
	int				fd;
	int				lines_file;
	char			*path;
	char			**file;
	int				height;
	int				width;
	int				start_i_map;
	int				end_i_map;
}					t_map;

typedef struct s_player
{
	char			dir;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				has_moved;
	int				move_x;
	int				move_y;
	int				rotate;
}					t_player;

typedef struct s_ray
{
	double			multiplier;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_dist;
	double			wall_x;
	bool			hit_side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_ray;

typedef struct s_img
{
	void			*img;
	int				*addr;
	int				pixel_bits;
	int				size_line;
	int				endian;
}					t_img;

typedef struct s_window
{
	int				x;
	int				y;
	int				i;
	int				j;
	int				color;
	void			*mlx;
	void			*win;
	t_img			screen;
}					t_window;

typedef struct s_data
{
	char			**map;
	t_window		window;
	t_ray			ray;
	t_map			map;
	t_texture		texture;
	t_player		player;
	int				**texture_pix;
	int				**textures;
}					t_data;

#endif
