/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:36:22 by hel-asli          #+#    #+#             */
/*   Updated: 2024/01/22 03:11:24 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// define BUFFER_SIZE 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// headers

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdlib.h>
// fun prototype
char	*get_next_line(int fd);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*read_from_file(char *buffer, int fd);
int		ft_strchr(char *str);
char	*read_line(char *buffer);

#endif
