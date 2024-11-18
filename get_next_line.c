/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:31:03 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/18 18:11:30 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buffer, char *tmr)
{
	int		ind;
	char	*temp;
	char	*rawline;

	rawline = tmr;
	ind = 1;
	while (ft_strchr(rawline, '\n') == -1)
	{
		ind = read(fd, buffer, BUFFER_SIZE);
		if (ind == -1)
			return (NULL);
		if (ind == 0)
			break ;
		buffer[ind] = '\0';
		temp = rawline;
		rawline = ft_strjoin(rawline, buffer);
		free(temp);
		temp = NULL;
	}
	if (!rawline || rawline[0] == '\0')
		return (NULL);
	return (rawline);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*rawline;
	char		*line;
	static char	*toomuchread = NULL;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	rawline = read_line(fd, buffer, toomuchread);
	free(buffer);
	buffer = NULL;
	if (!rawline)
	{
		free(rawline);
		free(toomuchread);
		toomuchread = NULL;
		return (NULL);
	}
	line = ft_substrto(rawline, '\n');
	toomuchread = ft_substrfrom(rawline, '\n');
	free(rawline);
	return (line);
}
/* 
#include <stdio.h>

int main (void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
}
 */
