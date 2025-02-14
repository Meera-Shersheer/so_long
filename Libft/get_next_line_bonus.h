/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:02:33 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/10 04:45:43 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_LINE
#  define MAX_LINE 4096
# endif


# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# ifndef MAX_LINE
#  define MAX_LINE 4096
# endif

char	*check_new(char **newline, char **buffer, char *store, int fd);
char	*no_read(ssize_t bytes_read, char **buffer, char *store, char *excess);
char	*no_excess(int fd, char **buffer, char *store, char *excess);
char	*frees(char **store, char **line);
char	*big_line(char **store, char **line);
char	*get_next_line(int fd);
char	*process_excess(char excess[], char *store);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
#endif
