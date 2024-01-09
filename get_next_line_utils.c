/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:27:01 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/09 12:40:08 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* measures the lenght of t */
int	len_to_copy(t_list *list)
{
	int	len;

	while (list->str_read[len])
	{
		if (list->str_read[len] == '\n')
		{
			len++;
			return (len) ;
		}
		len++;
	}
	return (0);
}

/* copy a line from a linked list to a pointer */
void	copy_line(t_list *list, char *line)
{
	int	i;

	while (list)
	{
		i = 0;
		while (list->str_read[i])
		{
			if (list->str_read[i] == '\n')
			{
				*line++ = list->str_read[i];
				return ;
			}
			*line++ = list->str_read[i];
			i++;
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

	// interate until the last node
	*list = last_node(*list);
	// add node in the last position
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return ;
	// add str read to new node
	new_node->str_read = buff;
	new_node->next = NULL;
	//add node to the list
	*list = new_node;
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
void	clean_node(t_list *list)
{
	// busca la pimera linea desde el primer nodo
	// crea un nuevo nodo y copia el contenido despues de la primera linea
	// elimina el nodo viejo
	// agrega el nuevo nodo al inicio de la lista
	char	*temp;
	int	i;
	int	j;

	temp = NULL;
	i = 0;
	while (list)
	{
		while (*(list->str_read) && *(list->str_read) != '\n')
			list->str_read++;
		if (*(list->str_read) == '\n')
		{
			list->str_read++;
			// calculate lenght for malloc
			while (list->str_read[i])
				i++;
			temp = (char *)malloc(sizeof(char) * i + 1);
			j = 0;
			// if still there are str in the node copy it in temp
			while (list->str_read[j] != '\0')
			{
				temp[j] = list->str_read[j];
				j++;
			}
			list->str_read[j] = '\0';
		}
		list = list->next;
	}
	// create a new node
	create_node(&list, temp);
	free(temp);
}

