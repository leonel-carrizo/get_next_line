/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:26:39 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/17 01:25:57 by lcarrizo          ###   ##london.com     */
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
#  define BUFFER_SIZE 6
# endif

//Functions prototypes
char	*get_next_line(int fd);
char	*new_line(t_list *list);
void	copy_line(t_list *list, char *line);
int	len_to_copy(t_list *list);
int	find_new_line(t_list *list);
void	save_str(int fd, t_list **list);
void	create_node(t_list **list, char *buff);
void	clean_list(t_list **list);
void	add_str(t_list **ilist, char *str);
t_list	*last_node(t_list *list);

#endif
