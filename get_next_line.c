/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:31:03 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/12 12:23:37 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		len_ln;
	void	line[BUFFER_SIZE + 1];

	if (fd == -1)
		return (NULL);
	while (line[i] != '\n')
	{
		len_ln = read(fd, line, sizeof(char));
	}
	line[len_ln] = '\0';
	return (line);
}

int main (void)
{
	int		fd;

	fd = open("Test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}
