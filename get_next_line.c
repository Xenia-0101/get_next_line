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

char *get_next_line(int fd)
{
	int bytes_read;
	char *buff;
	static char *new_contents;
	t_list *new;
	t_list *lines;
	int i;

	buff = ft_calloc(BUFFER_SIZE, sizeof (char));
	lines = NULL;

	if (!new_contents)
	{
		new_contents = "";
	}

	// read n bytes and store them in buff
	bytes_read = read(fd, buff, BUFFER_SIZE);
	//	analyse buff
	//		- is there '\n' ?
	char *res = strchr(buff, '\n');
	if (res)
	{
		i = 0;
		// write first line until '\n'
		while (buff[i] != '\n')
		{
			write(1, &buff[i], 1);
			i++;
		}
		write(1, &buff[i], 1);
		i++;
		new = ft_lstnew(ft_substr(buff, i, bytes_read - i));
		// printf("REST: %s\n", (char *)new->content);
		ft_lstadd_back(&lines, new);
	}
	else
	{
		new = ft_lstnew(buff);
	}

	// printf("\n%s\n", buff);
	// printf("%d: >%s<\n", bytes_read, res);
	free(buff);

	return (new_contents);

}

int main(void)
{
	int fd = open("example.txt", O_RDONLY);

	get_next_line(fd);
	printf("\n***\n");
	return (0);
}
