#ifndef PROTOTYPE_H
# define PROTOTYPE_H

//main.c
int	ft_error_msg(t_err error, int status_code);

//exit_game.c
void    good_exit_game(t_data *data);
void    bad_exit_game(t_data *data);

//clean.c
int	ft_free_data(t_data *data);

//err_getter.c
const char	*ft_get_err_msg(t_err error);

//exit.c
void	ft_exit_cub(t_data *data, int exit_code);

//valid_file.c
bool	ft_valid_cub_file(char *file);

//game_controls.c
int	ft_set_player_direction(t_player *p);
int	ft_rotate(double *x, double *y, double angle);
int	ft_move(t_data *d, double dx, double dy);

//game_engine.c
void	ft_calc_dda(t_ray *ray, t_player *p);
void	ft_perform_dda(t_data *data, t_ray *ray);
void	ft_calc_line_height(t_ray *ray, t_player *player);
void	ft_setup_raycast_info(int x, t_ray *ray, t_player *player);


//game_loop.c
int	ft_close_hook(t_data *d);
int	ft_key_hook(int key, t_data *d);
int	ft_starting_game(t_data *d);

//game_render.c
int	ft_render_images(t_data *data);

//valid_map.c
int	ft_valid_map(t_data *data);
static bool	ft_is_map_last_element(t_map_det *map_det);
static int	ft_is_valid_char_in_map(t_data *data, char **map);
static bool	ft_is_map_sur_walls(t_data *data);
static bool	ft_check_player_pos(t_data *data, char **map);

//valid_map2.c
int	ft_pos_is_valid(t_data *data, char **map);
bool	ft_map_is_enclosed(t_data *data);
 
//valid_map_utils.c
bool	ft_is_white_space(char c);

//get_map_details.c
void    get_map_details(t_data *data, char **map);
int     get_player_data(t_data *data, int x, int y);

//valid_file.c
int valid_data(t_data *data, char *path);

//valid_texture.c
int valid_image(t_data *data, char **dir);

//valid_rgb.c
int valid_rgb(t_data *data, char **rgb);

//valid_map.c
int valid_map(t_data *data, char **map);

//utils.c
char    **read_file(char *path);
int ft_arrlen(char **arr);
char    **ft_arrdup(char **arr);
char    *ft_strjoin_free(char *s1, char *s2);

//for debug
void    debug(int n);
void    print_arr(char **arr);

#endif