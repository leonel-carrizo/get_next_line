/* ************************************************************************** */
/*                                                                            */
/*                                                       :::       ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:58:48 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/24 22:37:49 by lcarrizo          ###   ##london.com     */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* return a new line from file descriptor given */
char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*str_storage = NULL;
	char			*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buff = NULL;
	while (find_new_line(str_storage) < 1)
	{
		save_str(fd, &str_storage, &buff);
		if (!str_storage)
			return (NULL);
		if (!buff)
			break ;
	}
	new_line(&str_storage, &line);
	if (!line)
		return (NULL);
	return (line);
}

/* read and save the string read in a new node in the list */
void	save_str(int fd, t_list	**list, char **buff)
{
	ssize_t		bytes_read;
	char		*temp;

	temp = NULL;
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return ;
	bytes_read = read(fd, temp, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free (temp);
		*buff = NULL;
		return ;
	}
	temp[bytes_read] = '\0';
	*buff = temp;
	create_node(list, temp);
}

/* search New Line in all STORAGE and save it to return it */
void	new_line(t_list **list, char **line)
{
	t_list	*temp;
	size_t	i;
	size_t	len;

	temp = *list;
	len = 0;
	while (temp)
	{
		i = 0;
		while (temp->str_read[i])
		{
			len++;
			if (temp->str_read[i++] == '\n')
				break ;
		}
		temp = temp->next;
	}
	*line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return ;
	copy_line(list, *line, len);
	(*line)[len] = '\0';
}

/* clean list, remove lines returned */
// void	clean_list(t_list **list)
// {
// 	char	*new_str;
// 	t_list	*temp;

// 	if (!*list)
// 		return ;
// 	new_str = NULL;
// 	temp = *list;
// 	while (temp)
// 	{
// 		extra_line(temp, &new_str);
// 		temp = temp->next;
// 	}
// 	clean_nodes(list, new_str);
// }

/* checks if there are more characters after a new line and saves it */
// void	extra_line(t_list *list, char **str)
// {
// 	size_t	index;
// 	size_t	len;

// 	len = 0;
// 	index = 0;
// 	while (list->str_read[index] && list->str_read[index] != '\n')
// 		index++;
// 	if (list->str_read[index] == '\n')
// 	{
// 		index++;
// 		while (list->str_read[index] != '\0')
// 		{
// 			len++;
// 			index++;
// 		}
// 		if (len > 0)
// 		{
// 			index -= len;
// 			*str = add_str(list->str_read, len, index);
// 		}
// 	}
// }
