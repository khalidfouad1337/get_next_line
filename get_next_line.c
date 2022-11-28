/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:50:57 by kfouad            #+#    #+#             */
/*   Updated: 2022/11/28 18:00:54 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*s;
	char		*line;
	int			readline;

	s = malloc(BUFFER_SIZE + 1);
	if (!s)
		return (NULL);
	readline = 1;
	while (readline > 0 && !ft_strchr(save, '\n'))
	{
		readline = read(fd, s, BUFFER_SIZE);
		s[readline] = '\0';
		save = ft_strjoin(save, s);
	}
	line = newline(save);
	save = cutline(save);
	return (line);
}
