/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvernhes <hvernhes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:49:54 by hvernhes          #+#    #+#             */
/*   Updated: 2019/11/18 23:15:14 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		fd2;
	int		i;
	int		j;

	(void)ac;
	(void)av;
	i = 1;
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	if (fd == -1 || fd2 == -1)
	{
		printf("Usage: ./a.out <file1.txt> <file2.txt>\n");
		close(fd);
		close(fd2);
		return (1);
	}
	while((j = get_next_line(fd, &line)) > 0)
	{
		printf("%d Ligne %d : %s\n", j, i, line);
		i++;
		free(line);
		line = NULL;
	}
	printf("%d Ligne %d : %s\n", j, i, line);
	free(line);
	close(fd);
	i = 1;
	while((j = get_next_line(fd2, &line)) > 0)
	{
		printf("%d Ligne %d : %s\n", j, i, line);
		i++;
		free(line);
		line = NULL;
	}
	printf("%d Ligne %d : %s\n", j, i, line);
	free(line);
	close(fd2);
	return (0);
}
