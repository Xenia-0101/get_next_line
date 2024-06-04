/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:56:52 by xvislock          #+#    #+#             */
/*   Updated: 2024/06/03 16:56:52 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	temp = (char *)s;
	while (n > 0)
	{
		n--;
		temp[n] = '\0';
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*temp_d;
	char	*temp_s;
	size_t	i;

	temp_d = dest;
	temp_s = (char *)src;
	i = 0;
	if (!temp_d && !temp_s)
		return (NULL);
	while (i < n)
	{
		temp_d[i] = temp_s[i];
		i++;
	}
	return (dest);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	join = ft_calloc(len + 1, sizeof (char));
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	return (join);
}

int	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t elc, size_t els)
{
	void	*ptr;
	size_t	c;

	if (elc == 0 || els == 0)
	{
		elc = 1;
		els = 1;
	}
	c = elc * els;
	if (c < elc || c < els)
		return (NULL);
	ptr = malloc(c);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, c);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (start + 1 == 0)
		return (ft_calloc(0, 0));
	if (len == 0 || ft_strlen((char *)s) < (int)start + 1)
		return (ft_calloc(0, 0));
	if (len > (size_t)ft_strlen((char *)(s + start)))
		len = (size_t)ft_strlen((char *)(s + start));
	sub = malloc(sizeof (char) * len + 1);
	if (!sub)
		return (NULL);
	ft_bzero(sub, len + 1);
	ft_memcpy(sub, s + start, len);
	return (sub);
}

/*
 _______________________________________________________________________________________
|																						|
|									List Functions										|
|_______________________________________________________________________________________|

*/

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof (t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t_lst;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	t_lst = ft_lstlast(*lst);
	t_lst->next = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*t_lst;

	if (lst == NULL)
		return (NULL);
	t_lst = lst;
	while (t_lst->next != NULL)
	{
		t_lst = t_lst->next;
	}
	return (t_lst);
}
