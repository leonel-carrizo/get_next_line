/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:42:34 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/27 17:44:52 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/*  */
int main(int argc, char **argv)
{
	char	*line;
	int	fd;
	int	i;
	int	j;
	
	i = 1;
	while (argc >= 2 && i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		line = get_next_line(fd);
		j = 1;
		while (line && 1)
		{
			printf("%s line_\%d: %s", argv[i], j, line);
			free(line);
			if (ft_strncmp(argv[i], "test_files/read_error.txt", strlen(argv[i])) == 0 && j == 2)
			{
				close(fd);
				printf("ERROR, when reading the file\n\n");
				break ;
			}
			++j;
			line = get_next_line(fd);
		}
		++i;
		if (i == argc)
			break ;
		printf("-----next file-----\n\n");
	}
	return 0;
}
