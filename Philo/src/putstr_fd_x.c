/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:34:17 by moulmado          #+#    #+#             */
/*   Updated: 2022/08/13 13:36:18 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	putchar_fd_x(int c, int fd)
{
	write(fd, &c, 1);
}

void	putstr_fd_x(char *s, int fd)
{
	int index;

	index = 0;
	while (s[index])
		putchar_fd_x(s[index++], fd);
}