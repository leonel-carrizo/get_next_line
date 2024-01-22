/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:27:01 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/22 23:19:35 by lcarrizo          ###   ##london.com     */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* returns a new string from the given index and the specific lenght */
char	*add_str(char *str, int len, int index)
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

/* copy a line from a linked list to a pointer */
void	copy_line(t_list *list, char *line)
{
	int	i;
	int	j;

	i = 0;
	while (list)
	{
		j = 0;
		while (list->str_read[j])
		{
			if (list->str_read[j] == '\n')
			{
				line[i] = list->str_read[j];
				i++;
				line[i] = '\0';
				return ;
			}
			line[i] = list->str_read[j];
			i++;
			j++;
		}
		list = list->next;
	}
	line[i] = '\0';
}

/* create a node on list to add content read */
void	create_node(t_list **list, char *buff)
{
	t_list	*new_node;
	t_list	*last;
	int		i;

	i = 0;
	while (buff[i])
		i++;
	new_node = NULL;
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->str_read = add_str(buff, i, 0);
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

/* iterates through a node to search new line, if finds return 1 otherwise 0 */
int	find_new_line(t_list *list)
{
	int	i;

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

/* clean nodes after from a linked list */
void	clean_nodes(t_list **list, char *str)
{
	t_list	*temp;

	temp = *list;
	while (temp)
	{
		temp = temp->next;
		free((*list)->str_read);
		free(*list);
		*list = temp;
	}
	*list = NULL;
	if (str)
	{
		create_node(list, str);
		free(str);
	}
}
