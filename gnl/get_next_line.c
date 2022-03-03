/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 00:41:26 by kpucylo           #+#    #+#             */
/*   Updated: 2022/03/03 18:01:28 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*move_line(char *s)
{
	char	*dest;

	dest = ft_strchr_gnl(s, '\n');
	if (!dest)
	{
		free(s);
		return (NULL);
	}
	if (*(dest + 1))
		dest = ft_strdup_gnl(dest + 1);
	else
		dest = NULL;
	free(s);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*dest;
	char		buffer[BUFFER_SIZE + 1];
	int			size;

	size = read(fd, buffer, BUFFER_SIZE);
	if (size == -1)
		return (NULL);
	buffer[size] = 0;
	while (size > 0)
	{
		if (!s)
			s = ft_strdup_gnl(buffer);
		else
			s = ft_strjoin_gnl(s, buffer);
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = 0;
	}
	dest = ft_substr_gnl(s, 0, ft_strchr_gnl(s, '\n') - s + 1);
	s = move_line(s);
	return (dest);
}
