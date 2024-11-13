/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:30:07 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/13 11:00:33 by lmatkows         ###   ########.fr       */
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

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i ++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	char	*ret;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ret[i + j] = s2[j];
		j ++;
	}
	return (ret);
}
