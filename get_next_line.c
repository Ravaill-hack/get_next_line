/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:31:03 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/14 17:23:46 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_memset(void	*adr, int c, size_t len)
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

char	*ft_calloc(size_t size)
{
	char	*tab;

	tab = (char *)malloc((size + 1) * sizeof(char));
	if (tab == 0)
		return (NULL);
	ft_memset(tab, 0, size);
	return (tab);
}

/*
void	*cat_and_free(char *rwl, char *tmr, char *ln)
{
	char	*temp1;

	temp1 = ft_substrto(rwl, '\n');
	ln = ft_strjoin(tmr, temp1);
	free(temp1);
	temp1 = ln;
	ln = ft_strjoin(ln, "\n");
	free(temp1);
	free(tmr);
	tmr = ft_substrfrom(rwl, '\n');
	free(rwl);
}
*/

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
	{
		free(toomuchread);
		return (NULL);	
	}
	while ((ft_strchr(rawline, '\n') == -1) && (ind != 0))
	{
		buffer = ft_calloc(BUFFER_SIZE);
		ind = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		temp = rawline;
		rawline = ft_strjoin(rawline, buffer);
		free(temp);
		free(buffer);
	}
	//cat_and_free(rawline, toomuchread, line);
	temp = ft_substrto(rawline, '\n');
	line = ft_strjoin(toomuchread, temp);
	free(temp);
	temp = line;
	line = ft_strjoin(line, "\n");
	free(temp);
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
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
}

