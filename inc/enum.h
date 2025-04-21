/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:16:30 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/20 17:32:02 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

enum e_out
{
	SUCCESS,
	FAILURE,
	ERROR,
	BREAK,
	CONTINUE
};

enum e_err
{
	MLX_START,
	MLX_WIN,
	MLX_IMG,
	USER_NUM,
	USER_POS,
	USER_DIR,
	MAP_MISSING,
	MAP_TOO_SMALL,
	MAP_NO_WALLS,
	MAP_LAST,
	MAP_INVALID,
	FILE_INVALID,
	FILE_NOT_CUB,
	FILE_NOT_XPM,
	FILE_IS_DIR,
	FILE_INVALID_CHAR,
	COLOR_FLOOR_CEILING,
	COLOR_FLOOR,
	COLOR_CEILING,
	COLOR_MISSING,
	MALLOC,
	USAGE,
	TEX_RGB_VAL,
	TEX_MISSING,
	TEX_INVALID
};

enum e_tex
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

#endif
