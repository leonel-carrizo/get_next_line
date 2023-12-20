/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:04:37 by lcarrizo          #+#    #+#             */
/*   Updated: 2023/12/20 21:12:19 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
// Just to test: (DELETE WHEN FINISH)
# include <limits.h>
# include <string.h>
# include <stdio.h>

//to define nodo list
typedef struct		s_list
{
	char		*str_readós;
	struct s_list	*next;
}			t_list;

//to define predefined BUFFER SIZE 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//Functions prototypes
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t size)
void	check_new_line(char *buff);

#endif
