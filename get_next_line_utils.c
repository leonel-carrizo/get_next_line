/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:27:01 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/24 22:37:26 by lcarrizo          ###   ##london.com     */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* iterates through a node to search new line, if finds return 1 otherwise 0 */
int	find_new_line(t_list *list)
{
	size_t	i;

	if (list == NULL)
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

/* create a node on list to add content read */
void	create_node(t_list **list, char *buff)
{
	t_list	*new_node;
	t_list	*last;

	new_node = NULL;
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->str_read = buff;
	new_node->next = NULL;
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	last = *list;
	while (last->next)
		last = last->next;
	last->next = new_node;
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
		if ((*list)->str_read[j] != '\0')
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
	while ((*list)->str_read[index] != '\0')
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

/* clean nodes after from a linked list */
// void	clean_nodes(t_list **list, char *str)
// {
// 	t_list	*temp;

// 	temp = *list;
// 	while (temp)
// 	{
// 		temp = temp->next;
// 		free((*list)->str_read);
// 		free(*list);
// 		*list = temp;
// 	}
// 	*list = NULL;
// 	if (str)
// 		create_node(list, str);
// }
