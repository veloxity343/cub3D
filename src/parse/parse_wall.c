#include "cub3d.h"

void	ft_init_texture_pixels(t_data *data)
{
	int	i;

	if (data->texture_pixels)
		ft_free_strarr((void **)data->texture_pixels);
	data->texture_pixels = ft_calloc(HEIGHT + 1, sizeof * data->texture_pixels);
	if (!data->texture_pixels)
		ft_exit_and_free(data, ft_error_msg(ERR_MALC, 23));
	i = 0;
	while (i < HEIGHT)
	{
		data->texture_pixels[i] = ft_calloc(WIDTH + 1,
				sizeof * data->texture_pixels);
		if (!data->texture_pixels[i])
			ft_exit_and_free(data, ft_error_msg(ERR_MALC, 24));
		i++;
	}
}

/**
 * @brief Responsible to update the index of texture in current pixel.
 * This calculation is based in the ray direction and if the ray hit the wall.
 * @param data Dat aStructure
 * @param ray Ray structure
 */
static void	ft_get_texture_index(t_data *data, t_ray *ray)
{
	if (ray->hit_side == false)
	{
		if (ray->dir_x < 0)
			data->texture_det.index = WEST;
		else
			data->texture_det.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			data->texture_det.index = SOUTH;
		else
			data->texture_det.index = NORTH;
	}
}

void	ft_update_texture_pix(t_data *data, t_texture_det *tex, t_ray *r, int x)
{
	int			y;
	int			color;

	ft_get_texture_index(data, r);
	tex->x = (int)(r->wall_x * tex->size);
	if ((r->hit_side == false && r->dir_x < 0) || (r->hit_side == true
			&& r->dir_y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / r->line_height;
	tex->pos = (r->draw_start - HEIGHT / 2 + r->line_height / 2) * tex->step;
	y = r->draw_start;
	while (y < r->draw_end)
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = data->textures[tex->index][tex->size * tex->y + tex->x];
		if (tex->index == NORTH || tex->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			data->texture_pixels[y][x] = color;
		y++;
	}
}

static int	*ft_xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	ft_init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * data->texture_det.size * data->texture_det.size);
	if (!buffer)
		ft_exit_and_free(data, ft_error_msg(ERR_MALC, 25));
	y = 0;
	while (y < data->texture_det.size)
	{
		x = 0;
		while (x < data->texture_det.size)
		{
			buffer[y * data->texture_det.size + x]
				= tmp.addr[y * data->texture_det.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->view.mlx, tmp.img);
	return (buffer);
}

void	ft_setup_textures(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		ft_exit_and_free(data, ft_error_msg(ERR_MALC, 26));
	data->texture_det.size = TEX_SIZE;
	data->textures[NORTH] = ft_xpm_to_img(data, data->texture_det.north);
	data->textures[SOUTH] = ft_xpm_to_img(data, data->texture_det.south);
	data->textures[EAST] = ft_xpm_to_img(data, data->texture_det.east);
	data->textures[WEST] = ft_xpm_to_img(data, data->texture_det.west);
}
