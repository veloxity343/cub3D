#include "cub3d.h"

/**
 * @brief If map start with blank space, just keep going to the next item in
 * map. Check if the value is ray position. Check if is the value color to
 * floor or ceiling. Check if is a map data.
 * @param data Data structure
 * @param file File passed by param in program
 * @param i Index of line
 * @param j Index of next value in line
 * @return int Integer to handle if we must continue in loop, exit, go to next
 * line.
 */
static int	ft_handle_file_infos(t_data *data, char **file, int i, int j)
{
	while (ft_is_white_space(file[i][j]) == true)
		j++ ;
	if (ft_isdigit(file[i][j]) == false)
	{
		if (file[i][j + 1] != C_WHITE_S && file[i][j + 1])
		{
			if (ft_parse_tex_dir(&data->texture_det, file[i], j) == false)
				return (ft_error_msg(ERR_TEXT, FAILURE));
			return (BREAK);
		}
		else
		{
			if (ft_parse_tex_color(&data->texture_det, file[i], j) != 0)
				return (FAILURE);
			return (BREAK);
		}
	}
	else if (ft_isdigit(file[i][j]) == true)
	{
		data->map_det.start_i_map = i;
		if (ft_create_map(data) == false)
			return (ft_error_msg(ERR_MAP, 6));
		return (SUCCESS);
	}
	return (CONTINUE);
}

int	ft_file_to_variable(t_data *data)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (data->map_det.file[i] != NULL)
	{
		j = 0;
		while (data->map_det.file[i][j])
		{
			while (data->map_det.file[i][j] == '\n')
				i++;
			ret = ft_handle_file_infos(data, data->map_det.file, i, j);
			if (ret == BREAK)
				break ;
			else if (ret == FAILURE)
				return (FAILURE);
			else if (ret == SUCCESS)
				return (SUCCESS);
			j++;
		}
		i++;
	}
	return (0);
}
