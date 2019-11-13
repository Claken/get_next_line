/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:43:58 by sachouam          #+#    #+#             */
/*   Updated: 2019/11/13 17:45:07 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_one_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str && str[i] != '\n' && str[i])
		i++;
	if (!str || !(line = (malloc(sizeof(char) * (i + 1)))))
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int				get_next_line(int fd, char **line)
{
	int				byte;
	char			buffer[BUFFER_SIZE + 1];
	char			*tmp;
	static char		*str = NULL;
	int				i;

	if (fd < 0 || !line)
		return (-1);
	if ((byte = read(fd, buffer, BUFFER_SIZE)) == -1)
		return (-1);
	buffer[byte] = '\0';
	//printf("\nbuffer: %s\n\n", buffer);
	// si le str est NULL, on copie ce qui est dans le buffer dans le str
	if (!str)
	{
		if (!(str = ft_substr(buffer, 0, ft_strlen(buffer))))
			return (-1);
	}
	// si y a deja quelque chose dans le str...
	else if (str)
	{
		tmp = NULL;
		if (!(tmp = ft_strjoin(str, buffer)))
			return (-1);
		free(str);
		if (!(str = ft_substr(tmp, 0, ft_strlen(tmp))))
			return (-1);
		free(tmp);
		tmp = NULL;
	}
	// pour copier dans mon str le reste du buffer si on est pas tomber sur un r.a.l.l.,
	// On boucle tant qu'on est pas tombe sur un \n ou si on est pas arrive a la fin de str
	i = 0;
	while (!ft_strchr(str, '\n') && str[i++] /*&& byte > 0*/)
	{
		if ((byte = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (-1);
		buffer[byte] = '\0';
		if (!(tmp = ft_strjoin(str, buffer)))
			return (-1);
		free(str);
		if (!(str = ft_substr(tmp, 0, ft_strlen(tmp))))
			return (-1);
		free(tmp);
		tmp = NULL;
	}
	//if (byte > 0)
	// on envoie str dans la fonction pour 
	if (!(*line = ft_one_line(str)))
		return (-1);
	// pour sauvegarder ce qu'il y a apres le retour a la ligne
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i])
		i++;
	if (!(tmp = ft_substr(str, i, ft_strlen(str))))
		return (-1);
	free(str);
	if (!(str = ft_substr(tmp, 0, ft_strlen(tmp))))
		return (-1);
	free(tmp);
	tmp = NULL;
	//printf("\nstr: %s\n\n", str);
	// pour arreter si le nombre de bytes est de 0 : a changer
	if (byte == 0 && !ft_strchr(str, '\n'))
	{
		//if (!(*line = ft_substr("", 0, 2)))
		//	return (-1);
		return (0);
	}
	return (1);
}
