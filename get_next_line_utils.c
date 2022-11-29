/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:25:01 by kfouad            #+#    #+#             */
/*   Updated: 2022/11/29 17:06:02 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strchr(const char	*s, int c)
{
	char	*s1;
	int		i;
	int		a;

	i = 0;
	if (!s)
		return (0);
	s1 = (char *)s;
	a = ft_strlen(s1);
	while (i <= a)
	{
		if (s1[i] == (char)c)
			return (&s1[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	p = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (s1 && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = '\0';
	if (s1)
		free(s1);
	return (p);
}

char	*newline(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save[i])
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*cutline(char *save)
{
	char	*cut;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	if (save[i] == '\n')
		i++;
	cut = malloc((ft_strlen(save) - i) * sizeof(char));
	if (!cut)
		return (NULL);
	while (save[i])
	{
		cut[j] = save[i];
		i++;
		j++;
	}
	cut[j] = '\0';
	free(save);
	return (cut);
}
