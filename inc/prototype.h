#ifndef PROTOTYPE_H
# define PROTOTYPE_H

void	ft_init_map_handler(t_data *data, char *path);
void	ft_free1(void *ptr);
int	ft_valid_texture(t_texture_det *text);
bool	ft_valid_cub_file(char *file);
int	ft_valid_map(t_data *data);
int	ft_error_msg(t_err error, int status_code);

//is_invalid.c
int is_invalid(t_data *data, char *path);

//utils.c
int ft_arrlen(char **arr);
char    **ft_arrdup_n(char **arr, int n);
char    *ft_strjoin_free(char *s1, char *s2);

//for debug
void    debug(int n);
void    print_arr(char **arr);


#endif