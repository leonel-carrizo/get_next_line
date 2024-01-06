/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:27:01 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/05 14:47:09 by lcarrizo          ###   ##london.com     */
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

/* create a copy of src and copy it in dst */
size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (size <= 0)
		return (len);
	size -= 1;
	while (*src && size--)
	{
		printf("aqui quede");
		*dst++ = *src++;
	}
	*dst = '\0';
	return (len);
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

/* free memory from */
// void	clean_node(t_list *list)
// {
// 	// busca la pimera linea desde el primer nodo
// 	// crea un nuevo nodo y copia el contenido despues de la primera linea
// 	// elimina el nodo viejo
// 	// agrega el nuevo nodo al inicio de la lisa si hayconido en el
// }
