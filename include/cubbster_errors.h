/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubbster_errors.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:21:08 by dedelmir          #+#    #+#             */
/*   Updated: 2022/07/25 16:21:08 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBBSTER_ERRORS_H
# define CUBBSTER_ERRORS_H

# define INVALID_ARG_COUNT "Usage : ./cubbster <filename.cub>"
# define INVALID_FILENAME "No such file."
# define MEMORY_ERROR "Couldn't allocate memory. Exiting."
# define INVALID_EXTENSION ".cub extension expected."
# define MAP_INITIALIZATION_FAILED "Couldn't find actual version of mlx library. \
Sure you turn necessary files in the project directory."
# define IMG_INITIALIZATION_FAILED "Couldn't get image."

# include <unistd.h>
# include "../libft/libft.h"

void	put_error(char *str);

#endif
