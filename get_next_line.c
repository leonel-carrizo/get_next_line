/* ************************************************************************** */
/*                                                                            */
/*                                                       :::       ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:58:48 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/19 13:45:37 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* return a new line from file descriptor given */
char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*str_storage = NULL;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0) //TODO: check tester.
		return (NULL);
	line = NULL;
	buff = NULL;
	while (find_new_line(str_storage) < 1) //if there is not new line in storage, save read
	{
		save_str(fd, &str_storage, buff); // 1.save string read on storage.
		if (!buff)
			return (NULL);
	}
	// 3. create lines to return
	new_line(str_storage, &line);
	// 4. clean storage. new_line, buff, nodes.
	clean_list(&str_storage);
	if (!line)
		return (NULL);
	return (line);
}

/* create new node in list and save str read */
void	save_str(int fd, t_list	**list, char *buff)
{
	ssize_t		bytes_read;

	//read the file
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return ;
	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buff);
		return ;
	}
	buff[bytes_read] = '\0';
	// create new node.
	create_node(list, buff);
	//if (bytes_read < 0)
	//	free(buff);
}

/* search New Line in all STORAGE and return it */
void	new_line(t_list *list, char **line)
{
	t_list	*temp;
	int	i;
	int	len;

	temp = list;
	// calculate the lenght for malloc
	len = 0;
	while (temp)
	{
		i = 0;
		while (temp->str_read[i])
		{
			if (temp->str_read[i] == '\n')
			{
				len++;
				break ;
			}
			i++;
			len++;
		}
		temp = temp->next;
	}
	*line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return ;
	copy_line(list, *line);
}

// ---------------------------------- MAIN ---------------------------------- //
int	main(void)
{
	int		fd;
	char	*lines;
	int	i;

	fd = open("tests/test.txt", O_RDONLY);
	i = 0;
	while (1)
	{
		lines = get_next_line(fd);
		if (lines == NULL)
			return (1);
		printf("Line %d: |%s|\n",i , lines);
		i++;
		free(lines);
	}
	close(fd);
	return (0);
}

/*----------------------------------------------------------------------------*/
/* Write a function that returns a line read from a file descriptor:
 * fd: The file descriptor to read from
 * Read line: correct behavior
 * NULL: there is nothing else to read, or an error occurred.
 * CHECK MEMORY LEACK -> valgrind a.out --leak-check=yes my_program arg1 arg2
 * -----------------------------------------------------------------------------
 * - Repeated calls (e.g., using a loop) to your get_next_line() function 
 *  should let you read the text file pointed to by the file descriptor, 
 *  one line at a time. 
 * - Your function should return the line that was read.
 * - If there is nothing else to read or if an error occurred, 
 *   it should return NULL.
 * - Function must works as expected both when reading a file and 
 *  when reading from the standard input.
 * - Please note that the returned line should include the terminating \n 
 *   character,
 *  except if the end of file was reached and does not end with a \n character.
 * - add this option to your: compiler call: -D BUFFER_SIZE=n 
 *  It will define the buffer size for read(). 
 *  The buffer size value will be modified by your peer-evaluators and 
 *  the Moulinette 
 *  in order to test your code. 
 *  (cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c)
 * - An undefined behavior when reading a binary file. 
 *  However, you can implement a logical way to handle this behavior 
 *  if you want to.
 * - An undefined behavior if the file pointed to by 
 *   the file descriptor changed 
 *  since the last call whereas read() didn’t reach the end of file.
 * - Try to read as little as possible each time get_next_line() is called. 
 *  If you encounter a new line, you have to return the current line. 
 *  Don’t read the whole file and then process each line.
 * - You are not allowed to use your libft in this project.
 * - lseek() is forbidden.
 *- Global variables are forbidden.
 */
