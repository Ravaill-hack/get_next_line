/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:31:03 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/13 21:23:42 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_memset(void	*adr, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)adr;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (adr);
}

char	*get_next_line(int fd)
{
	int			ind;
	char		*line;
	static char	*toomuchread = NULL;
	static char	*readok = NULL;
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
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
		ind = read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(line, buffer);
	}
	free(readok);
	readok = ft_substrto(line, '\n');
	ret = ft_strjoin(toomuchread, readok);
	free(toomuchread);
	ret = ft_strjoin(ret, "\n");
	toomuchread = ft_substrfrom(line, '\n');
	free(buffer);
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
