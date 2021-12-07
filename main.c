/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:22:22 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/07 19:56:44 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
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
