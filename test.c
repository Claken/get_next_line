#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <string.h>

# define BUFFER_SIZE 100

void Func() {
  static int x = 0;
  // |x| is initialized only once across five calls of |Func| and the variable
  // will get incremented five times after these calls. The final value of |x|
  // will be 5.
  x++;
  printf("%d\n", x);  // outputs the value of |x|
}

static char		*ft_one_line(char *buf)
{
	int		i;
	char	*line;

	i = 0;
	while (buf && buf[i] != '\n' && buf[i])
		i++;
	if (!buf || !(line = (malloc(sizeof(char) * (i + 1)))))
		return (NULL);
	i = 0;
	while (buf[i] != '\n' && buf[i])
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int main(int ac, char **av)
{  
	char	buffer[BUFFER_SIZE + 1];
	char	*line = NULL;
	int		byte;
	int		a;
	char	static *str = NULL;
	char	*tmp = NULL;
	int		i;

	(void)ac;
	a = open(av[1], O_RDONLY);
	if (!str)
	{
		byte = read(a, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		if (!(str = ft_strdup(buffer)))
			return (0);
	}
	while (!ft_strchr(str, '\n') && byte > 0)
	{
		byte = read(a, buffer, BUFFER_SIZE);
		if (!(tmp = ft_strjoin(str, buffer)))
			return (0);
		free(str);
		if (!(str = ft_strdup(tmp)))
			return (0);
		free(tmp);
		tmp = NULL;
	}
	if (byte > 0)
		if (!(line = ft_one_line(str)))
			return (0);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!(tmp = ft_substr(str, i, ft_strlen(str))))
		return (0);
	free(str);
	if (!(str = ft_strdup(tmp)))
		return (0);
	printf("str : %s\n", str);
	free(tmp);
	tmp = NULL;
	free(str);
	str = NULL;
	close(a);
	printf("line : %s\n\nbuffer : %s\n\n", line, buffer);
	free(line);
	line = NULL;
	return 0;
}
