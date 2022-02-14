#include "get_next_line.h"

char *ft_strdup(char *str)
{
	int i;
	char *new;

	i = 0;
	new = (char*)malloc(sizeof(char)*(i + 1));
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	int i;
	int res;
	char c;
	char line[8000000] = {};

	i = 0;
	res = 1;
	line[0] = 0;
	while ((res = read(fd, &c, 1)) > 0)
	{
		line[i++] = c;
		if (c == '\n')
			break;
	}
	if (line[0] == 0)
		return NULL;
	return (ft_strdup(line));
}

int	main(int argc, char **argv)
{
	char *line;
	(void)argc;
	int fd = open(argv[1], O_RDONLY);
	while((line = get_next_line(fd)))
	{
		printf ("%s",line);
		free (line);
	}
}
