/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:30:07 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/13 10:47:45 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
char	*ft_substrfrom(char	*str, char	c)
{
	int		i;
	int		j;
	int		start;
	char	*dest;

	i = 0;
	j = 0;
	dest = NULL;
	while ((str[i] != c) && (str[i] != '\0'))
		i++;
	i++;
	start = i;
	while (str[i] != '\0')
		i ++;
	dest = (char *)malloc((i - start + 1) * sizeof(char));
	while (str[start] != '\0')
	{
		dest[j] = str[start];
		start ++;
		j ++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substrto(char	*str, char	c)
{
	int		i;
	int		end;
	char	*dest;

	i = 0;
	j = 0;
	dest = NULL;
	while ((str[i] != c) && (str[i] != '\0'))
		i++;
	end = i - 1;
	dest = (char *)malloc((end + 2) * sizeof(char));
	i = 0;
	while ((str[i] != '\0') && (str[i] != c))
	{
		dest[i] = str[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}
