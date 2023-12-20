/* ************************************************************************** */
/*                                                                            */
/*                                                       :::       ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:58:48 by lcarrizo          #+#    #+#             */
/*   Updated: 2023/12/20 21:12:15 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	ssize_t		n_bytes;

	n_bytes = read(fd, buff, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE <=0 || n_bytes < 0)
		return (NULL);
	// 1. 

	return (line);
}


int	main(void)
{
	int		fd;
	char	*line;

	fd = open("tests/test", O_RDONLY);
	while (fd == 1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s\n", line);
		free(line);
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
