/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:50:57 by kfouad            #+#    #+#             */
/*   Updated: 2022/11/30 19:15:47 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_read(int fd, char *str)
{
	int			readline;
	char		buf[BUFFER_SIZE + 1];

	readline = 1;
	while (readline > 0 && !ft_strchr(str, '\n'))
	{
		readline = read(fd, buf, BUFFER_SIZE);
		if (readline < 0)
		{
			free(str);
			return (0);
		}
		//if (readline < 0)
		//	break ;
		buf[readline] = '\0';
		str = ft_strjoin(str, buf);
	}
	if (!str)
		return (0);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2)
		return (0);
	save = ft_read(fd, save);
	if (!save)
		return (0);
	if (ft_strlen(save) >= 0)
	{
		line = newline(save);
		save = cutline(save);
		return (line);
	}
	return (NULL);
}
