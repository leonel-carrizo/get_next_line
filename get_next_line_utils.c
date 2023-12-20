/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:04:16 by lcarrizo          #+#    #+#             */
/*   Updated: 2023/12/20 21:12:21 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	if (s)
	{
		while (*s)
		{
			s++;
			len++;
		}
		return (len);
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	len;
	if (size <= 0)
		return (len);
	size -= 1;
	while (*src && size--)
		*dst++ = *src++;
	*dst = '\0';
	return (len);
}
