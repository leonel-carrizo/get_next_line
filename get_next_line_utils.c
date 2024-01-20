/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:27:01 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/20 19:04:23 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/**************************************************************************** */

#include "get_next_line.h"

/* measures the lenght of t */
int	len_str(char *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

/* copy a line from a linked list to a pointer */
void	copy_line(t_list *list, char *line)
{
	int	i;
	int	j;

	i = 0;
	while (list )
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

/* return a pointer a the las node from a linked list */
t_list	*last_node(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

/* create a node on list to add content read */
void	create_node(t_list **list, char *buff)
{
	t_list 	*new_node = NULL;
	t_list	*last = *list;
	int		i;

	new_node = (t_list *)malloc(sizeof(t_list));
	new_node->str_read = (char *)malloc(sizeof(char) * len_str(buff) + 1);
	if (!new_node || !new_node->str_read)
		return ;
	i = 0;
	while (buff[i])
	{
		new_node->str_read[i] = buff[i];
		i++;
	}
	new_node->str_read[i] = '\0';
	new_node->next = NULL;
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	last = last_node(*list);
	last->next = new_node;
}

/* iterates through a node to search new line, if finds return 1 otherwise 0 */
int	find_new_line(t_list *list)
{
	int	i;
	t_list	*last;

	if (list == NULL)
		return (0);
	last = last_node(list);
	i = 0;
	while (last->str_read[i])
	{
		if (last->str_read[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/* clean list, remove lines returned */
void	clean_list(t_list **list)
{
	char	*new_str;
	t_list	*temp_list = NULL;
	int	len;
	int	j;

	if (!*list)
		return ;
	new_str = NULL;
	temp_list = *list;
	len = 0;
	while (temp_list)
	{
		j = 0;
		while (temp_list->str_read[j] && temp_list->str_read[j] != '\n')
			j++;
		if (temp_list->str_read[j] == '\n')
		{
			j++;
			// calculate lenght for malloc
			while (temp_list->str_read[j] != '\0')
			{
				len++;
				j++;
			}
			if (len > 0)
			{
				new_str = (char *)malloc(sizeof(char) * (len + 1));
				if (!new_str)
					return ;
				j -= len;
				len = 0;
				while (temp_list->str_read[j] != '\0')
				{
					new_str[len] = temp_list->str_read[j];
					j++;
					len++;
				}
				new_str[len] = '\0';
			}
		}
		temp_list = temp_list->next;
	}
	if (new_str)
	{
		add_str(list, new_str);
		free(new_str);
	}
	if (!new_str && !temp_list)
	{
		temp_list = *list;
		while (temp_list)
		{
			temp_list = temp_list->next;
			free((*list)->str_read);
			free(*list);
			*list = temp_list;
		}
		*list = NULL;
	}
}

/* take a pointer to a pointer linked list to modify, add new nodo in the 
 * beginnig of the list whith a new string and delete the head */
void	add_str(t_list **list, char *str)
{
	t_list *new_node = NULL;
	t_list	*temp = NULL;
	int	i;

	if (str)
	{

		new_node = (t_list *)malloc(sizeof(t_list));
		if (!new_node)
			return ;
		new_node->str_read = (char *)malloc(sizeof(char) * len_str(str) + 1);
		i = 0;
		while (str[i])
		{
			new_node->str_read[i] = str[i];
			i++;
		}
		new_node->str_read[i] = '\0';
		new_node->next = NULL;
		(*list)->next = new_node;
		// add the new node with the new string and replace the list head.
		if(list)
		{
			temp = *list;
			*list = (*list)->next;
			free(temp);
		}
	}
}
