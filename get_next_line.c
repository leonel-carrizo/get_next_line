/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:58:48 by lcarrizo          #+#    #+#             */
/*   Updated: 2023/12/13 04:33:10 by lcarrizo          ###   ##london.com     */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t		BUFFER_SIZE;
	char		*buff;
	ssize_t		n_bytes;
	char 		*line;

	if (fd == -1)
	{
		perror("Error");
		return ("nada");
	}
	BUFFER_SIZE = 10;
	buff = (char *)malloc(BUFFER_SIZE);
	if (!buff)
		return (NULL);
	line = buff;
	while ((n_bytes = read(fd, buff, BUFFER_SIZE)) > 0)
		write(1, buff, n_bytes);
	if(n_bytes == 0)
		return ("menos");
	return (line);
}

int	main(void)
{
	int	fd;
	const char	*path;
	char	*line;
	
	path = "/home/l3o/42-London/get_next_line/get_next_line-trash/tests/test.txt";
	fd = open(path, O_RDONLY);
	// loop for calling  get)next_line()
	line =	get_next_line(fd);
	printf("The text is: %s\n", line);

	close(fd);
	return (0);
}

// PASOS:
// Ser capas de acceder al archivo.
// Abrir el archivo.
// Almacenar memoria para guardar la linea encontrada.
// 	- Array.
// 	- Listas Enlazadas.
// Leer el contenido del archivo ya sea:
// 	- leer caracter por caracter.
// 	- leer cadena por cadena.
// 	- leer todo el archivo.
// Encontrar la nueva linea ('\n').
// Almacenar la linea encontrada.
// Retornar el (escribir en la terminal) la linea leida.
// Liberar la memoria de la linea retornada.
// Repetir el hasta el llegar al final del archivo.
// Cerrar el archivo.
//
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
// app.diagrams.net
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Write a function that returns a line read from a file descriptor:
 * fd: The file descriptor to read from
 * Read line: correct behavior
 * NULL: there is nothing else to read, or an error occurred.
 * ----------------------------------------------------------------------------
 * - Repeated calls (e.g., using a loop) to your get_next_line() function 
 *  should let you read the text file pointed to by the file descriptor, 
 *  one line at a time. 
 * - Your function should return the line that was read.
 * - If there is nothing else to read or if an error occurred, it should return NULL.
 * - Function must works as expected both when reading a file and 
 *  when reading from the standard input.
 * - Please note that the returned line should include the terminating \n character,
 *  except if the end of file was reached and does not end with a \n character.
 * - add this option to your: compiler call: -D BUFFER_SIZE=n 
 *  It will define the buffer size for read(). 
 *  The buffer size value will be modified by your peer-evaluators and the Moulinette 
 *  in order to test your code. (cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c)
 * - An undefined behavior when reading a binary file. 
 *  However, you can implement a logical way to handle this behavior if you want to.
 * - An undefined behavior if the file pointed to by the file descriptor changed 
 *  since the last call whereas read() didn’t reach the end of file.
 * - Try to read as little as possible each time get_next_line() is called. 
 *  If you encounter a new line, you have to return the current line. 
 *  Don’t read the whole file and then process each line.
 * - You are not allowed to use your libft in this project.
 * - lseek() is forbidden.
 * - Global variables are forbidden.
 */
