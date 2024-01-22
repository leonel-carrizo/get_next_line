/* ************************************************************************** */
/*                                                                            */
/*                                                       :::       ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:58:48 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/22 13:46:14 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* clean list, remove lines returned */
void	clean_list(t_list **list)
{
	char	*new_str;
	t_list	*temp;
	int		len;
	int		j;

	if (!*list)
		return ;
	new_str = NULL;
	temp = *list;
	len = 0;
	while (temp)
	{
		j = 0;
		// checks if there is anything beyond the new line
		while (temp->str_read[j] && temp->str_read[j] != '\n')
			j++;
		if (temp->str_read[j] == '\n')
		{
			j++;
			while (temp->str_read[j] != '\0')
			{
				len++;
				j++;
			}
			//if there are chars after the new line save it
			if (len > 0)
			{
				new_str = (char *)malloc(sizeof(char) * (len + 1));
				if (!new_str)
					return ;
				j -= len;
				len = 0;
				while (temp->str_read[j] != '\0')
				{
					new_str[len] = temp->str_read[j];
					j++;
					len++;
				}
				new_str[len] = '\0';
			}
		}
		temp = temp->next;
	}
	//clean
	clean_nodes(list, new_str);
}

/* return a new line from file descriptor given */
char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*str_storage = NULL;
	char			*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	buff = NULL;
	while (find_new_line(str_storage) < 1)
	{
		save_str(fd, &str_storage, &buff);
		if (!buff)
			break ;
	}
	new_line(str_storage, &line);
	clean_list(&str_storage);
	if (!line)
		return (NULL);
	return (line);
}

/* create new node in list and save str read */
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
		temp = NULL;
		return ;
	}
	temp[bytes_read] = '\0';
	*buff = temp;
	create_node(list, temp);
	free(temp);
	temp = NULL;
}

/* search New Line in all STORAGE and return it */
void	new_line(t_list *list, char **line)
{
	t_list	*temp;
	int		i;
	int		len;

	if (!list)
		return ;
	temp = list;
	len = 0;
	while (temp)
	{
		i = 0;
		while (temp->str_read[i++])
		{
			len++;
			if (temp->str_read[i] == '\n')
				break ;
		}
		temp = temp->next;
	}
	*line = (char *)malloc(sizeof(char) * (len + 2));
	if (!line)
		return ;
	copy_line(list, *line);
}

// ---------------------------------- MAIN ---------------------------------- //
int	main(void)
{
	int		fd;
	char	*lines;
	int		i;

	fd = open("tests/notes.md", O_RDONLY);
	i = 0;
	while (1)
	{
		lines = get_next_line(fd);
		if (!lines)
			break ;
		printf("Line %d: %s", i, lines);
		i++;
		free(lines);
	}
	close(fd);
	return (0);
}
