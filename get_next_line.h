/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:26:39 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/22 13:46:43 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
// Just to test: (DELETE WHEN FINISH)
# include <limits.h>
# include <string.h>
# include <stdio.h>

//to define nodo list
typedef struct	s_list
{
	char		*str_read;
	struct s_list	*next;
}			t_list;

//to define predefined BUFFER SIZE 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

//Functions prototypes
char	*get_next_line(int fd);
void	new_line(t_list *list, char **line);
void	copy_line(t_list *list, char *line);
int	find_new_line(t_list *list);
void	save_str(int fd, t_list **list, char **buff);
void	create_node(t_list **list, char *buff);
void	clean_list(t_list **list);
void	clean_nodes(t_list **list, char *str);

#endif
