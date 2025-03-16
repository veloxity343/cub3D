/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:16:06 by rcheong           #+#    #+#             */
/*   Updated: 2025/03/16 13:21:41 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_map_tile
{
	C_WALL = '1',
	C_BACK_G = '0',
	C_WHITE_S = ' '
} t_map_tile;

typedef enum e_err
{
	ERR_ARGS,
	ERR_MALC,
	ERR_CUB,
	ERR_FILE_OPEN,
	ERR_FILE_READ,
	ERR_MAP,
	ERR_MAP7,
	ERR_MAP8,
	ERR_MAP_LAST,
	ERR_MAP_DIR,
	ERR_MAP9,
	ERR_MAP_CHAR,
	ERR_SING_PLAYER,
	ERR_PLA_POS,
	ERR_TEXT,
	ERR_TEXT_MAP,
	ERR_TEXT_COL,
	ERR_TEXT_PATH,
	ERR_RGB,
	ERR_RGB_VAL,
	ERR_MLX_IMG,
	ERR_MLX_WIN,
	ERR_MLX_INIT
}	t_err;

typedef enum e_output
{
	SUCCESS,
	FAILURE,
	BREAK = 3,
	CONTINUE
}	t_output;

typedef enum e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_dir;

#endif
