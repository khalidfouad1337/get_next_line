/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:41:06 by kfouad            #+#    #+#             */
/*   Updated: 2022/11/29 21:57:04 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int		fd;


	fd = open("test.txt", O_RDONLY);
	printf("%s here",get_next_line(fd));
	//printf("%s",get_next_line(fd));
	//printf("%s",get_next_line(fd));
	//printf("%s",get_next_line(fd));
	//printf("%s",get_next_line(fd));
	//printf("%s",get_next_line(fd));
	//printf("%s",get_next_line(fd));
	return 0;
}
