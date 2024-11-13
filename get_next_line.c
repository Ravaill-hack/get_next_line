/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:31:03 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/13 10:26:01 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substrend(char	*str, int	start)
{
	int		i;
	char	*dest;

	i = 0;
	// rajouter malloc dest
	while ((str[start] != '\0') && (dest[i] != '\0'))
	{
		dest[i] = str[start];
		i ++;
		start ++;
	}
	return (dest);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i ++;
	}
	return (-1);
}

char	*next_line(char *tab)
{
	int	i;

	i = ft_strchr(tab, '\n');
	if (i == (-1))
		return (NULL);
	return (ft_substrend(tab, i));
}

char	*get_next_line(int fd)
{
	int			ind;
	int			i;
	static char	*line = NULL;
	static char *toomuchread = NULL;
	char		*buffer;
	char		*ret;

	i = 0;
	ind = -1;
	line = NULL;
	if (fd == -1)
		return (NULL);
	while ((ft_strchr(line, '\n') == 0) && (ind != 0))
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		ind = read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(line, buffer);
		//free(buffer);
	}
	ret = ft_strjoin(toomuchread, substrto(line, '\n'));
	toomuchread = susbtrfrom(line, '\n');
	return (ret);
}

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
	printf("%s",get_next_line(fd));
	printf("%d\n",fd);
	close(fd);
}

