/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvernhes <hvernhes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:49:54 by hvernhes          #+#    #+#             */
/*   Updated: 2019/11/14 15:12:28 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	(void)ac;
	i = 1;
	fd = open(av[1], O_RDONLY);
	while((j = get_next_line(fd, &line)) > 0)
	{
		printf("%d Ligne %d : %s\n", j, i, line);
		i++;
		free(line);
		//line = NULL;
	}
	printf("%d Ligne %d : %s\n", j, i, line);
	free(line);
	close(fd);
	/*
	i = 1;
	fd = open(av[2], O_RDONLY);
	while((j = get_next_line(fd, &line)) > 0)
	{
		printf("%d Ligne %d : %s\n", j, i, line);
		i++;
		free(line);
		//line = NULL;
	}
	printf("%d Ligne %d : %s\n", j, i, line);
	free(line);
	close(fd);
	*/
	return (0);
}
