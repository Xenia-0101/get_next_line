/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:46:33 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/02 16:46:33 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_calloc(int count, int size)
{
	int res;
	char *ptr;

	if (count == 0 || size == 0)
	{
		return (NULL);
	}
	res = count * size;
	if (res < count || res < size)
	{
		return (NULL);
	}
	ptr = (char *)malloc(res);
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (res > 0)
	{
		res--;
		ptr[res] = '\0';
	}
	return (ptr);
}

int has_newline(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
	{
		return (0);
	}
	while (str[i])
	{
		i++;
	}
	return (i);
}

char *ft_strjoin(char *str1, char *str2)
{
	int i;
	int j;
	char *str3;

	i = ft_strlen(str1);
	j = ft_strlen(str2);
	str3 = ft_calloc((i + j + 1), sizeof (char));
	if (str3 == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (str1 && str1[i])
	{
		str3[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		str3[i + j] = str2[j];
		j++;
	}
	free(str1);
	return (str3);
}


char *read_fd(int fd, char *cont)
{
	char buff[BUFFER_SIZE + 1];
	int i;

	i = BUFFER_SIZE;
	// TODO: take care of invalid read
	// TODO: take care of the end of file
	while (i == BUFFER_SIZE && !has_newline(cont))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			return (NULL);
		}
		buff[i] = '\0';
		cont = ft_strjoin(cont, buff);
	}

	return (cont);
}

char *get_line(char *cont)
{
	int i;
	int j;
	char *current;

	i = 0;
	while (cont[i] != '\n')
	{
		i++;
	}
	current = ft_calloc(sizeof (char), (i + 1));
	if (!current)
		return (NULL);
	j = 0;
	while (j < i)
	{
		current[j] = cont[j];
		j++;
	}
	while (current[j])
	{
		current[j] = 'x';
		j++;
	}
	return (current);
}

char *move_next(char *src, char *dest)
{
	int i;
	int to_cpy;

	if (src == NULL)
		return (NULL);
	i = 0;
	to_cpy = ft_strlen(src);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (dest[i])
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);

}


char *get_next_line(int fd)
{
	static char *fd_content;
	char *current;
	int i;

	// if there is nothing useful in fd_content, read file
	if (!fd_content || !has_newline(fd_content))
	{
		fd_content = read_fd(fd, fd_content);
		if (fd_content == NULL)
		{
			return (NULL);
		}
	}
	//	now we have a newline char in fd_content ** OR end
	current = get_line(fd_content);
	i = 0;
	while (fd_content[i] != '\n')
	{
		i++;
	}
	fd_content = move_next(&fd_content[i + 1], fd_content);

	// printf("%s\n", current);
	return (current);

}

int main(void)
{
	int fd = open("example.txt", O_RDONLY);

	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));


	// printf("%s", get_next_line(fd));
	// printf("\n***\n");
	// printf("%s", get_next_line(fd));
	// printf("\n***\n");
	// printf("%s", get_next_line(fd));
	// printf("\n***\n");
	// printf("%s", get_next_line(fd));
	// printf("\n***\n");
	// printf("%s", get_next_line(fd));
	// printf("\n***\n");
	// printf("%s", get_next_line(fd));
	// printf("\n***\n");
	// printf("%s", get_next_line(fd));
	// printf("\n***\n");
	// printf("%s", get_next_line(fd));
	// printf("\n***\n");
	// printf("%s", get_next_line(fd));
	// printf("\n***\n");
	return (0);
}

// valgrind --leak-check=full --show-leak-kinds=all -s  --track-origins=yes ./a.out
