/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line _bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:21:23 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/10 16:18:46 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*process_pre_excess(char *excess, char *store)
{
	char	*new;
	char	temp[MAX_LINE];

	ft_bzero(temp, MAX_LINE);
	new = ft_strchr((const char *)(excess), '\n');
	if (new == NULL)
	{
		ft_strlcat(store, excess, MAX_LINE);
		ft_bzero(excess, MAX_LINE);
	}
	else
	{
		*new = 0;
		ft_strlcat(store, excess, MAX_LINE);
		ft_strlcat(store, "\n", MAX_LINE);
		if (ft_strlen(new + 1) != 0)
		{
			ft_strlcpy(temp, new + 1, MAX_LINE);
			ft_bzero(excess, MAX_LINE);
			ft_strlcpy(excess, temp, MAX_LINE);
		}
		else
			ft_bzero(excess, MAX_LINE);
	}
	return (store);
}

char	*check_new(char **newline, char **buffer, char *store, int fd)
{
	char	*line;
	ssize_t	bytes_read;

	line = NULL;
	while (*newline == NULL)
	{
		if (ft_strlen(store) + ft_strlen(*buffer) >= MAX_LINE)
		{
			if (BUFFER_SIZE <= MAX_LINE)
				line = big_line(&store, &line);
			else
				line = big_line(buffer, &line);
		}
		ft_strlcat(store, *buffer, MAX_LINE);
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		(*buffer)[bytes_read] = '\0';
		*newline = ft_strchr((const char *)(*buffer), '\n');
	}
	return (line);
}

char	*no_excess(int fd, char **buffer, char *store, char *excess)
{
	char	*newline;
	char	*line;

	line = NULL;
	newline = ft_strchr((const char *)(*buffer), '\n');
	if (newline == NULL)
		line = check_new(&newline, buffer, store, fd);
	if (newline != NULL)
	{
		*newline = 0;
		if (ft_strlen(store) + ft_strlen(*buffer) >= MAX_LINE)
			line = big_line(buffer, &line);
		else
			ft_strlcat(store, *buffer, MAX_LINE);
		if (ft_strlen(newline + 1) != 0)
			ft_strlcpy(excess, newline + 1, MAX_LINE);
		ft_strlcat(store, "\n", MAX_LINE);
	}
	frees(buffer, NULL);
	if (line != NULL)
		return (big_line(&store, &line));
	return (ft_strjoin(line, store));
}


char	*no_read(ssize_t bytes_read, char **buffer, char *store, char *excess)
{
	char	*line;

	line = NULL;
	if (bytes_read < 0)
	{
		ft_bzero(excess, MAX_LINE);
		return (frees(buffer, &line));
	}
	if (bytes_read == 0)
	{
		if (excess[0] == 0)
			return (frees(buffer, NULL));
		ft_strlcpy(store, process_pre_excess(excess, store), MAX_LINE);
		frees(buffer, NULL);
		return (ft_strjoin(line, store));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		store[MAX_LINE];
	static char	excess[OPEN_MAX][MAX_LINE];
	char		*line;
	char		*buffer;
	ssize_t		bytes_read;

	ft_bzero(store, MAX_LINE);
	line = NULL;
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (no_read(bytes_read, &buffer, store, excess[fd]));
	buffer[bytes_read] = '\0';
	ft_strlcpy(store, process_pre_excess(excess[fd], store), MAX_LINE);
	if (excess[fd][0] == 0)
		return (no_excess(fd, &buffer, store, excess[fd]));
	ft_strlcat(excess[fd], buffer, MAX_LINE);
	frees(&buffer, NULL);
	return (ft_strjoin(line, store));
}
