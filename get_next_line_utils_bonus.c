/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:27:01 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/25 10:51:57 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* iterates through a linked list searching new line, return 1 otherwise 0 */
int	find_new_line(t_list *list)
{
	size_t	i;

	if (!list)
		return (0);
	while (list->next)
		list = list->next;
	i = 0;
	while (list->str_read[i])
	{
		if (list->str_read[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/* copy a line from a linked list and free every and clean each copied node */
void	copy_line(t_list **list, char *line, size_t len)
{
	size_t	i;
	size_t	j;
	t_list	*temp;

	temp = *list;
	i = 0;
	while (*list && i < len)
	{
		j = 0;
		while ((*list)->str_read[j] && i < len)
			line[i++] = (*list)->str_read[j++];
		if ((*list)->str_read[j])
			extra_str(list, j);
		temp = temp->next;
		free((*list)->str_read);
		(*list)->str_read = NULL;
		free(*list);
		*list = NULL;
		*list = temp;
	}
}

/* checks if there are more string after a new line and saves it in the list */
void	extra_str(t_list **list, size_t index)
{
	char	*new_str;
	size_t	len;

	new_str = NULL;
	len = 0;
	while ((*list)->str_read[index])
	{
		len++;
		index++;
	}
	if (len > 0)
	{
		index -= len;
		new_str = add_str((*list)->str_read, len, index);
	}
	if (new_str)
		create_node(list, new_str);
}

/* returns a new string from the given index and the specific lenght */
char	*add_str(char *str, size_t len, size_t index)
{
	char	*new_str;
	int		i;

	new_str = NULL;
	new_str = (char *)malloc(sizeof(char) * len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[index])
	{
		new_str[i] = str[index];
		i++;
		index++;
	}
	new_str[i] = '\0';
	return (new_str);
}
