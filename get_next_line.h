/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:21:26 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/08 16:50:05 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		ft_strlen(char *s);
char	*ft_nul(char *tmp);
char	*get_next_line(int fd);
int		ft_get_n(char *tmp);
char	*ft_strdup(char *tmp, char *str, int fr);
char	*ft_join(char *tmp, char *buf);
char	*ft_substr(char *tmp, int end);
#endif
