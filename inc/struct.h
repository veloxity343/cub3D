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

/**
 * @brief A structure representing an MLX image and its metadata.
 * @param img Pointer to the MLX image.
 * @param adr Pointer to the pixel data address.
 * @param px_bits Bits per pixel.
 * @param size_line Size of one line of the image in bytes.
 * @param endian Endian setting of the image data.
 * @param h Height of the image in pixels.
 * @param w Width of the image in pixels.
 */
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

/**
 * @brief A structure for storing texture information and settings.
 * @param north Path to the north texture.
 * @param south Path to the south texture.
 * @param west Path to the west texture.
 * @param east Path to the east texture.
 * @param floor Pointer to RGB array for floor color.
 * @param ceiling Pointer to RGB array for ceiling color.
 * @param size Size of each texture in pixels.
 * @param index Index of the current texture.
 * @param step Step size for sampling the texture.
 * @param pos Current position in the texture.
 * @param hex_f Floor color in hexadecimal.
 * @param hex_c Ceiling color in hexadecimal.
 * @param dir Texture sampling direction offset.
 */
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

/**
 * @brief A structure representing a framebuffer used for rendering.
 * @param img Pointer to the image buffer.
 * @param offset Offset applied to rendering position.
 * @param view_dist Viewing distance in pixels.
 * @param tile_size Size of a single tile in pixels.
 * @param size Overall framebuffer size.
 * @param map Pointer to the map data used for rendering.
 */
typedef struct s_framebuffer
{
	t_img		*img;
	t_dir_int	offset;
	int			view_dist;
	int			tile_size;
	int			size;
	char		**map;
}	t_framebuffer;

/**
 * @brief A structure representing map file data and dimensions.
 * @param eom End-of-map flag.
 * @param line Current line index in map parsing.
 * @param h Height of the map in tiles.
 * @param w Width of the map in tiles.
 * @param fd File descriptor of the map file.
 * @param file Array of lines from the map file.
 * @param path File path to the map file.
 */
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

/**
 * @brief A structure holding raycasting data for a single screen column.
 * @param map Current grid position of the ray.
 * @param step Step direction for grid traversal.
 * @param dir Direction of the ray.
 * @param side_dist Distance to the next x/y side.
 * @param delta_dist Distance between sides along ray direction.
 * @param cam_x X position on the camera plane.
 * @param wall_x Exact x-position where the wall was hit.
 * @param wall_dist Distance from the player to the wall.
 * @param side Side of the wall that was hit (0: x-side, 1: y-side).
 * @param line_h Height of the wall line to draw.
 * @param start Start pixel for drawing.
 * @param end End pixel for drawing.
 */
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

/**
 * @brief A structure representing the player's state.
 * @param move Direction of movement input.
 * @param plane 2D camera plane vector.
 * @param pos Current player position.
 * @param dir_t Transformed direction vector.
 * @param dir Starting direction (N, S, E, W).
 * @param moved Flag to indicate if player moved.
 * @param rotate Rotation direction input.
 */
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


/**
 * @brief Main game structure containing all subcomponents and game state.
 * @param map_info Information about the map file and dimensions.
 * @param tex_info Texture settings and file paths.
 * @param framebuffer Image buffer used for rendering.
 * @param player Player position and movement data.
 * @param ray Raycasting data used for rendering.
 * @param time Frame timing value.
 * @param win_h Window height in pixels.
 * @param win_w Window width in pixels.
 * @param map Pointer to the processed map array.
 * @param cub_file Raw lines from the .cub file.
 * @param mlx Pointer to the MLX instance.
 * @param win Pointer to the MLX window.
 * @param tex_px 2D array of texture pixel data.
 * @param tex 2D array of texture references.
 */
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
