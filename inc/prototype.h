#ifndef PROTOTYPE_H
# define PROTOTYPE_H

void	ft_init_map_handler(t_data *data, char *path);
void	ft_free1(void *ptr);
int	ft_valid_texture(t_texture_det *text);
bool	ft_valid_cub_file(char *file);
int	ft_valid_map(t_data *data);


#endif