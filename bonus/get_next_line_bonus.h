/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:36:24 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/27 14:41:02 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*str_read;
	struct s_list	*next;
}			t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		find_new_line(t_list *list);
char	*get_next_line(int fd);
char	*add_str(char *str, size_t len, size_t index);
void	save_str(int fd, t_list **list, char **buff);
void	create_node(t_list **list, char *buff);
void	new_line(t_list **list, char **line);
void	copy_line(t_list **list, char *line, size_t len);
void	extra_str(t_list **list, size_t index);
void	clean_node(t_list **list);

#endif
