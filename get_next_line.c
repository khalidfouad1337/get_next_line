/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:50:57 by kfouad            #+#    #+#             */
/*   Updated: 2022/12/05 17:31:49 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_read(int fd, char *save)
{
	int			readline;
	char		buf[BUFFER_SIZE + 1];

	readline = 1;
	while (readline > 0 && !ft_strchr(save, '\n'))
	{
		readline = read(fd, buf, BUFFER_SIZE);
		if (readline < 0)
		{
			free(save);
			return (0);
		}
		//if (readline < 0)
		//	break ;
		buf[readline] = '\0';
		save = ft_strjoin(save, buf);
	}
	//if (!str)
	//	return (0);
	return (save);
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
