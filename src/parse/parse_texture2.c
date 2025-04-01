#include "cub3d.h"

bool	ft_parse_tex_dir(t_texture_det *text_det, char *row, int i)
{
	if (row[2] != C_WHITE_S)
		return (false);
	if (row[i] == 'N' && row[i + 1] == 'O' && text_det->north == NULL)
		text_det->north = ft_parse_text_path(row, (i + 3));
	else if (row[i] == 'S' && row[i + 1] == 'O' && text_det->south == NULL)
		text_det->south = ft_parse_text_path(row, (i + 3));
	else if (row[i] == 'W' && row[i + 1] == 'E' && text_det->west == NULL)
		text_det->west = ft_parse_text_path(row, (i + 3));
	else if (row[i] == 'E' && row[i + 1] == 'A' && text_det->east == NULL)
		text_det->east = ft_parse_text_path(row, (i + 3));
	else
		return (false);
	return (true);
}

/**
 * @brief Extract the path of the Texture to be used. Calloc of -3 (2 char and
 * white space, but +1 to end string)
 * @param string
 * @param i Start index in a row with the value of texture
 * @return char* = Row with a value of texture
 */
static char	*ft_parse_text_path(char *row, int i)
{
	int		len;
	char	*path;
	int		j;

	j = 0;
	while (row[i] && ft_is_white_space(row[i]) == true)
		i++;
	len = ft_strlen(row);
	path = ft_calloc(len - 2, sizeof(char));
	if (!path)
		return (NULL);
	while (row[i] && (ft_is_white_space(row[i]) == false))
		path[j++] = row[i++];
	path[j] = '\0';
	return (path);
}
