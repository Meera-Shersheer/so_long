/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:15:53 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/10 16:21:39 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*big_line(char **store, char **line)
{
	char	*replace;

	replace = NULL;
	replace = ft_strjoin(*line, *store);
	if (line != NULL)
		free(*line);
	*line = replace;
	ft_bzero(*store, ft_strlen(*store));
	return (*line);
	return (NULL);
}

char	*frees(char **store, char **line)
{
	if (store != NULL && *store != NULL)
		free(*store);
	if (store != NULL)
		*store = NULL;
	if (line != NULL && *line != NULL)
		free(*line);
	if (line != NULL)
		*line = NULL;
	return (NULL);
}
