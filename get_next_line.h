#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
	int BUFFER_SIZE = 5;
# endif

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	*ft_calloc(size_t elc, size_t els);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
