/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:26:39 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/22 23:30:19 by lcarrizo          ###   ##london.com     */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*str_read;
	struct s_list	*next;
}			t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*add_str(char *str, int len, int index);
void	new_line(t_list *list, char **line);
void	copy_line(t_list *list, char *line);
void	extra_line(t_list *list, char *str);
void	save_str(int fd, t_list **list, char **buff);
void	create_node(t_list **list, char *buff);
void	clean_list(t_list **list);
void	clean_nodes(t_list **list, char *str);
int		find_new_line(t_list *list);

#endif
