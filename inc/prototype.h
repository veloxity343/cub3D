/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:22:17 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/04/20 17:33:00 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

void	init_game(t_game *game);
void	init_img_clean(t_img *img);
void	init_ray(t_ray *ray);

void	init_pattern(t_game *game);
void	init_tex(t_tex *tex);

void	init_mlx_img(t_game *game, t_img *img, int w, int h);
void	init_mlx_img_tex(t_game *game, t_img *img, char *path);
void	init_mlx(t_game *game);

int		create_map(t_game *game, char **file, int i);

int		parse_file(t_game *game, char **map);

void	parse_game(char *path, t_game *game);

int		parse_tex(t_game *game, t_tex *tex, char *line, int j);

int		is_whitespace(char c);
size_t	max_len(t_map *map, int i);

void	init_player_dir(t_game *game);

void	get_input(t_game *game);

int		move_player(t_game *game);

int		validate_move(t_game *game, double new_x, double new_y);

int		rotate_player(t_game *game, double rotate_dir);

int		error_msg(char *info, int error, int code, int custom);
int		print_error_val(int info, int rerror, int code, int custom);

void	clean(t_game *game, int code);
int		quit(t_game *game);

char	*ft_free(char **str);
void	free_tab(void **tab);
int		free_game(t_game *game);

int		raycast(t_player *player, t_game *game);


void	set_img_px(t_img *img, int x, int y, int colour);
void	render_raycast(t_game *game);
int		render_img(t_game *game);

void	init_tex_px(t_game *game);

void	render_tiles(t_game *game, t_framebuffer *m);
void	update_tex_px(t_game *game, t_tex *tex, t_ray *ray, int x);

int		validate_file(char *arg, int cub);

int		validate_sides(t_map *map, char **map_tab);

int		validate_map(t_game *game, char **map_tab);
int     valid_map(t_game *data, char **map);
int     valid_image(t_game *data, char **dir);
int     valid_rgb(t_game *data, char **rgb);
void    get_map_details(t_game *data, char **map);
int valid_player_pos(char **map, int x, int y);
int get_player_data(t_game *data, int x, int y);
char    **read_file(char *path);
void    free_arr(char **arr);
int ft_arrlen(char **arr);
char    **ft_arrdup(char **arr);
char    *ft_strjoin_free(char *s1, char *s2);
void    debug(int n);
void    print_arr(char **arr);

int		validate_tex(t_tex *tex, t_game *game);

#endif
