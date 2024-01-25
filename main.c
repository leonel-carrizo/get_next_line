/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:26:00 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/25 11:56:32 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/* for mandatory part */
int	main(void)
{
	int		fd;
	char	*lines;
	int		i;

	fd = open("test_files/big_line_no_nl", O_RDWR);
	i = 1;
	while (1)
	{
		lines = get_next_line(fd);
		if (!lines)
			break ;
		printf("Line %d: %s", i, lines);
		i++;
		free(lines);
	}
	if (fd > 0)
		close(fd);
	return (0);
}

/* for bonus part */
//void	save_str(int fd, t_list	**list, char **buff);
//void	create_node(t_list **list, char *buff);
//void	new_line(t_list **list, char **line);
//
//int	main(void)
//{
//	int	fd;
//	int	fd1;
//	int	fd2;
//	char	*file1;
//	char	*file2;
//	char	*file3;
//
//
//	fd = open("test_files/test.txt", O_RDONLY);
//	fd1 = open("test_files/notes.md", O_RDONLY);
//	fd2 = open("README.md", O_RDONLY);
//	while (1)
//	{
//		file1 = get_next_line(fd);
//		file2 = get_next_line(fd1);
//		file3 = get_next_line(fd2);
//		if (!file1 && !file2 && !file3)
//			break ;
//		if (file1)
//			printf("File_1: %s\n", file1);
//		//printf("File_2: %s\n", file2);
//		//printf("File_3: %s", file3);
//		free(file1);
//		free(file2);
//		free(file3);
//	}
//	close(fd);
//	close(fd1);
//	close(fd2);
//	return (0);
//}
