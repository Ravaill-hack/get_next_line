/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:31:03 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/14 11:41:19 by lmatkows         ###   ########.fr       */
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if ((nmemb == 0) || (size == 0))
	{
		nmemb = 0;
		size = 0;
	}
	tab = malloc(nmemb * size);
	if (tab == 0)
		return (NULL);
	ft_memset(tab, 0, nmemb * size);
	return (tab);
}

//char	*assembly_line(char *toomuchread, char *rawline)
//{
//	
//}

char	*get_next_line(int fd)
{
	int			ind;
	char		*rawline;
	static char	*toomuchread = NULL;
	char		*buffer;
	char		*line;
	char 		*temp;

	ind = -1;
	rawline = NULL;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((ft_strchr(rawline, '\n') == -1) && (ind != 0))
	{
		buffer = ft_calloc(1, BUFFER_SIZE + 1);
		ind = read(fd, buffer, BUFFER_SIZE);
		temp = rawline;
		rawline = ft_strjoin(rawline, buffer);
		free(temp);
	}
	line = ft_substrto(rawline, '\n');
	line = ft_strjoin(toomuchread, line);
	line = ft_strjoin(line, "\n");
	free(toomuchread);
	toomuchread = ft_substrfrom(rawline, '\n');
	free(rawline);
	return (line);
}


int main (void)
{
	int		fd;
	char	*line;

	fd = open("Test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
}

