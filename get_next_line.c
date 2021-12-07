/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:56:01 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/07 20:07:54 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_get_n(char *tmp)
{
	int	i;

	i = 0;
	if (!tmp)
		return (-1);
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*new;

	if (!str)
		return (NULL);
	i = -1;
	new = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new)
		return (NULL);
	while (str[++i])
		new[i] = str[i];
	new[i] = '\0';
	return (new);
}


char	*ft_join(char *tmp, char *buf)
{
	int	len1;
	int	len2;
	char	*new;
	int i;

	if ((!tmp || !*tmp) && buf)
		return (ft_strdup(buf));
	else if (!tmp && !buf)
		return (NULL);
	len1 = ft_strlen(tmp);
	len2 = ft_strlen(buf);
	new = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new)
		return (NULL);
	i = -1;
	new[len1 + len2] = '\0';
	while (++i < len1 && i < len2 )
	{
		if (i < len1 && tmp[len1 - i - 1])
			new[len1 - i - 1] = tmp[len1 - i - 1];
		if (i < len2 && buf[len2 - i - 1])
			new[len1 + len2 - i - 1] = buf[len2 - i - 1];
	}
	free(tmp);
	return (new);
}
char	*ft_substr(char *tmp, int end)
{
	char	*new;
	int		i;

	if (!tmp)
		return (NULL);
	new = malloc(sizeof(char) * (end + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (++i < end)
		new[i] = tmp[i];
	new[i] = '\0';
	free(tmp);
	return (new);
}

char *get_next_line(int fd)
{
	static char *tmp;
	char		*buf;
	char		*result;
	char		*tmp2;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (ft_get_n(tmp) <= 0 || ft_get_n(tmp) == ft_strlen(tmp))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		buf[ret]= '\0';
		tmp = ft_join(tmp, buf);
		if (ret < BUFFER_SIZE)
			break;
	}
	result = ft_substr(tmp, ft_get_n(tmp));
	tmp2 = tmp;
	tmp = ft_strdup(tmp + ft_get_n(tmp) + 1);
	free(tmp2);
	return(result);
}

int main()
{
	int		fd;
	char *test;
	int		r = 0;

	fd = open("brams42.txt", O_RDONLY);
	while ((test = get_next_line(fd)) != NULL)
	{
		printf("%s", test);
		r++;
	}
}
