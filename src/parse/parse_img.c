#include "cub3d.h"

void	ft_init_img(t_data *data, t_img *image, int width, int height)
{
	image->img = mlx_new_image(data->view.mlx, width, height);
	if (image->img == NULL)
		ft_exit_and_free(data, ft_error_msg(ERR_MLX_IMG, 20));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	ft_set_image_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;  

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}

void	ft_init_texture_img(t_data *data, t_img *image, char *path)
{
	image->img = mlx_xpm_file_to_image(data->view.mlx, path,
			&data->texture_det.size, &data->texture_det.size);
	if (image->img == NULL)
		ft_exit_and_free(data, ft_error_msg(ERR_MLX_IMG, 21));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}
