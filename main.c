/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:26:00 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/01/24 12:25:29 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*lines;
	int		i;

	fd = open("tests/files/big_line_no_nl", O_RDWR);
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
