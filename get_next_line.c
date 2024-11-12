/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:31:03 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/12 14:28:18 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int		len_ln;
	char	*line;
	int		i;

	i = 0;
	if (fd == -1)
		return (NULL);
	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (line[i] != '\n')
	{
		len_ln = read(fd, &line[i], sizeof(char));
		printf("%c", line[i]);
		if ((line[i] == '\0') || (line[i] == '\n'))
			return (line);
		i ++;
		//printf("%d\n", i);
	}
	line[i] = '\0';
	return (line);
}


int main (void)
{
	int		fd;

	fd = open("Test.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	//printf("%s", get_next_line(fd));
}
