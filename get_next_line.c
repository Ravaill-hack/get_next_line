/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:31:03 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/12 16:02:24 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			ret;
	static char	*line;
	int			i;

	i = 0;
	if (fd == -1)
		return (NULL);
	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (ret != 0)
	{
		ret = read(fd, &line[i], sizeof(char));
		if ((line[i] == '\0') || (line[i] == '\n'))
			return (line);
		i ++;
	}
	if (ret == 0)
	{
		free (line);
		return (NULL);	
	}
	line[i] = '\0';
	return (line);
}
/*
#include <stdio.h>

int main (void)
{
	int		fd;

	fd = open("Test.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	//printf("%s", get_next_line(fd));
}
*/
