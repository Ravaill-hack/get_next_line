/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:14:27 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/11/18 13:47:12 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 1 || BUFFER_SIZE > 8000000
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 4
#  endif
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
char	*ft_substrto(char *str, char c);
char	*ft_substrfrom(char *str, char c);
int		ft_strchr(char *str, char c);

#endif
