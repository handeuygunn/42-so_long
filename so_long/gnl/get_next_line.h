/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huygun <huygun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:16:22 by huygun            #+#    #+#             */
/*   Updated: 2023/12/24 17:16:24 by huygun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_strlen1(char const *s);
char	*ft_strjoin1(char *s1, char *s2);
char	*get_next_line(int fd);
char	*find_line(char *str);
char	*ft_strchr(char *s, int c);
char	*new_str(char *str);

#endif
