/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:31:03 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/12 12:13:46 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		fd;
	int		len_ln;
	void	buf[BUFFER_SIZE + 1];

	fd = open("Test.txt", O_RDONLY);
	if (fd == -1)
		return (NULL);
	len_ln = read(fd, buf, BUFFER_SIZE);
	buf[len_ln] = '\0';
	return (buf);
}
