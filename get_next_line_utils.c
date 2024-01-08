/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:27:01 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/08 21:45:29 by lcarrizo          ###   ##london.com     */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* measures the lenght of the string given */
size_t	ft_strlen(char *s)
{
	size_t	len;

	if (s)
	{
		while (*s)
		{
			s++;
			len++;
		}
		return (len);
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

/* free memory */
// void	clean_node(t_list *list)
// {
// 	// busca la pimera linea desde el primer nodo
// 	// crea un nuevo nodo y copia el contenido despues de la primera linea
// 	// elimina el nodo viejo
// 	// agrega el nuevo nodo al inicio de la lista
// 	t_list	*temp;
//
// 	temp = NULL;
//
// }
