/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvernhes <hvernhes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:49:54 by hvernhes          #+#    #+#             */
/*   Updated: 2019/11/11 18:18:44 by sachouam         ###   ########.fr       */
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

	(void)ac;
	i = 1;
	fd = open(av[1], O_RDONLY);
	while((get_next_line(fd, &line)) > 0)
	{
		printf("Ligne %d : %s\n", i, line);
		i++;
		free(line);
		//line = NULL;
	}
	printf("Ligne %d : %s\n", i, line);
	//free(line);
	return (0);
}
