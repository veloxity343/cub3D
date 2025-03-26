#ifndef PROTOTYPE_H
# define PROTOTYPE_H

/*-------------src-------------*/
//main.c
int	ft_error_msg(t_err error, int status_code);

//exit_game.c
void    good_exit_game(t_data *data);
void    bad_exit_game(t_data *data);

/*-------------utils-------------*/
//clean.c
int	ft_free_data(t_data *data);

//err_getter.c
const char	*ft_get_err_msg(t_err error);

//exit.c
void	ft_exit_cub(t_data *data, int exit_code);

//get_map_details.c
void    get_map_details(t_data *data, char **map);
int     get_player_data(t_data *data, int x, int y);

//utils.c
char    **read_file(char *path);
int ft_arrlen(char **arr);
char    **ft_arrdup(char **arr);
char    *ft_strjoin_free(char *s1, char *s2);

/*------------validate--------------*/
//valid_file.c
bool	ft_valid_cub_file(char *file);
int valid_data(t_data *data, char *path);

//valid_map.c
int valid_map(t_data *data, char **map);

//valid_move.c
static bool	ft_is_valid_pos_in_map(t_data *data, double x, double y);
int	ft_validate_move(t_data *data, double new_x, double new_y);

//valid_texture.c
int valid_image(t_data *data, char **dir);

//valid_rgb.c
int valid_rgb(t_data *data, char **rgb);

/*-------------game-------------*/
//game_controls.c
int	ft_set_player_direction(t_player *p);
int	ft_rotate(double *x, double *y, double angle);
int	ft_move(t_data *d, double dx, double dy);

//game_render.c
int	ft_render_images(t_data *data);

//game_loop.c
int	ft_starting_game(t_data *d);

//game_engine.c
void	ft_setup_raycast_info(int x, t_ray *ray, t_player *player);
void	ft_calc_line_height(t_ray *ray, t_player *player);
void	ft_perform_dda(t_data *data, t_ray *ray);
void	ft_calc_dda(t_ray *ray, t_player *p);

/*-------------debug-------------*/
//for debug
void    debug(int n);
void    print_arr(char **arr);

#endif