Write a function that returns a line read from a file descriptor:
fd: The file descriptor to read from
Read line: correct behavior
NULL: there is nothing else to read, or an error occurred.
CHECK MEMORY LEACK:
valgrind --show-error-list=yes --track-origins=yes --leak-check=full --tool=memcheck
-------------------------------------------------------------------------------
- Repeated calls (e.g., using a loop) to your get_next_line() function 
 should let you read the text file pointed to by the file descriptor, 
 one line at a time. 
- Your function should return the line that was read.
- If there is nothing else to read or if an error occurred, 
  it should return NULL.
- Function must works as expected both when reading a file and 
 when reading from the standard input.
- Please note that the returned line should include the terminating \n 
  character,
 except if the end of file was reached and does not end with a \n character.
- add this option to your: compiler call: -D BUFFER_SIZE=n 
 It will define the buffer size for read(). 
 The buffer size value will be modified by your peer-evaluators and 
 the Moulinette 
 in order to test your code. 
 (cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c)
- An undefined behavior when reading a binary file. 
 However, you can implement a logical way to handle this behavior 
 if you want to.
- An undefined behavior if the file pointed to by 
  the file descriptor changed 
 since the last call whereas read() didn’t reach the end of file.
- Try to read as little as possible each time get_next_line() is called. 
 If you encounter a new line, you have to return the current line. 
 Don’t read the whole file and then process each line.
- You are not allowed to use your libft in this project.
- lseek() is forbidden.
- Global variables are forbidden.

-------------------------------------------------------------------------------

## LEAKS DE MEMORIA

## BORRADO DE NODOS.

# Entendiendo el **heap** y **stack**
los datos almacenados automaticamente al crear una variable
se almacenan en el **stak** y los datos almacenados cuando usamos **malloc**
para reservar memoria para una variable se almacenan en el **heap**
y esto es algo que debemos manejar para liberar este espacio de memoria
para usarlo posteriormente


18/01/2024

**OJO**: cuando no hay un strig extra despues de copiar la linea nueva, no se estan borrando todos esos nodos
	que quedaron desde el principio, esta retornando la linea pero cuando coincide el buffer con una nueva
	linea, de debe eliminar toda la lista, ver funcion `add_str`


22/01/20124
hay fugas de memoria. la memoria allocada con malloc en la funcion `create_node` no
`new_node` = 592c0 --> `**list`
`new_node->str_read` = 592e0 --> `*list->str_read`

-----DENTRO DE `SAVE_STR`------
`new_node` = 59730
`new_node->str_read` = 59750

