/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:50:57 by kfouad            #+#    #+#             */
/*   Updated: 2022/11/29 17:25:21 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		s[BUFFER_SIZE + 1];
	char		*line;
	int			readline;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2)
		return (0);
	readline = 1;
	while (readline && !ft_strchr(save, '\n'))
	{
		readline = read(fd, s, BUFFER_SIZE);
		if (readline < 0)
		{
			free(save);
			return (0);
		}
		s[readline] = '\0';
		save = ft_strjoin(save, s);
	}
	if (ft_strlen(save) >= 0 && readline >= 0)
	{
		line = newline(save);
		save = cutline(save);
		return (line);
	}
	free(save);
	return (NULL);
}
