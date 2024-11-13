/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:31:03 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/13 14:21:45 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int			ind;
	static char	*line = NULL;
	static char	*toomuchread = NULL;
	char		*buffer;
	char		*ret;

	ind = -1;
	line = NULL;
	if (fd == -1)
		return (NULL);
	while ((ft_strchr(line, '\n') == -1) && (ind != 0))
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
		ind = read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(line, buffer);
	}
	ret = ft_strjoin(toomuchread, ft_substrto(line, '\n'));
	ret = ft_strjoin(ret, "\n");
	toomuchread = ft_substrfrom(line, '\n');
	return (ret);
}
/*
int main (void)
{
	int		fd;
	fd = open("Test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}
*/
