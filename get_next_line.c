/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:56:01 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/08 14:24:07 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *tmp;
	char		*buf;
	char		*result;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!tmp || ft_get_n(tmp) <= 0 || ft_get_n(tmp) == ft_strlen(tmp))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		buf[ret]= '\0';
		tmp = ft_join(tmp, buf);
		if (ret < BUFFER_SIZE)
			break;
	}
	free(buf);
	result = ft_substr(tmp, ft_get_n(tmp));
	if (tmp && ft_strlen(tmp + ft_get_n(tmp)) > 1)
		tmp = ft_strdup(tmp + ft_get_n(tmp) + 1, 1);
	else if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	return(result);
}
/*
int main()
{
	int		fd;
	char *test;
	int		r = 0;

	fd = open("42_no_nl", O_RDONLY);
	while ((test = get_next_line(fd)))
	{
		printf("%s", test);
		free(test);
		r++;
	}
}*/
