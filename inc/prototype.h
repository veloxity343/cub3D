/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:22:17 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/04/29 18:57:05 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

//init_game.c
void	init_game(t_game *game);
void	init_img_clean(t_img *img);
void	init_ray(t_ray *ray);

//init_img.c
void	init_pattern(t_game *game);
void	init_tex_px(t_game *game);
void	init_tex(t_tex *tex);

//init_mlx.c
void	init_mlx_img(t_game *game, t_img *img, int w, int h);
void	init_mlx_img_tex(t_game *game, t_img *img, char *path);
void	init_mlx(t_game *game);

//init_map.c
int		create_map(t_game *game, char **file, int i);

//utils2.c
size_t	max_len(t_map *map, int i);

//player_direction.c
void	init_player_dir(t_game *game);

//player_input.c
void	get_input(t_game *game);

//player_movement.c
int		move_player(t_game *game);

//player_position.c
int		validate_move(t_game *game, double new_x, double new_y);

//player_rotate.c
int		rotate_player(t_game *game, double rotate_dir);

//error.c
int		error_msg(char *info, int error, int code, int custom);

//exit.c
void	clean(t_game *game, int code);
int		quit(t_game *game);

//clean.c
char	*ft_free(char **str);
void	free_tab(void **tab);
int		free_game(t_game *game);

//game_raycast.c
int		render_img(t_game *game);
int		raycast(t_player *player, t_game *game);
void	setup_dda(t_ray *ray, t_player *player);
void	do_dda(t_game *game, t_ray *ray);
void	calc_wall_height(t_ray *ray, t_game *game, t_player *player);
void	engine_loop(t_game *game, t_tex *tex, t_ray *ray, int x);

//valid_args.c
int		validate_file(char *arg, int cub);

//valid_map.c
int		valid_map(t_game *data, char **map);

//valid_texture.c
int		valid_image(t_game *data, char **dir);

//valid_rgb.c
int		valid_rgb(t_game *data, char **rgb);

//utils.c
char	*read_file(char *path);
void	free_arr(char **arr);
int		ft_arrlen(char **arr);
char	**ft_arrdup(char **arr);
char	*ft_strjoin_free(char *s1, char *s2);

//utils2.c
void	get_map_details(t_game *data, char **map);
int		valid_player_pos(char **map, int x, int y);
int		get_player_data(t_game *data, int x, int y);
int		check_map_double_newline(char *map);

#endif
