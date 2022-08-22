/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:05:11 by moulmado          #+#    #+#             */
/*   Updated: 2022/08/15 16:00:11 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_b.h"

int	ft_atoi(const char *s)
{
	int		nbr;
	int		n;
	int		i;

	n = 1;
	nbr = 0;
	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r' || s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			n *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr = (nbr * 10) + (s[i] - '0');
		i++;
	}
	return (nbr * n);
}

static int	ft_isdigit(int i)
{
	if (i >= 48 && i <= 57)
		return (1);
	return (0);
}

int	parse(int ac, char **av)
{
	int	a;
	int	b;

	a = 1;
	if (ac != 5 && ac != 6)
		return (0);
	while (av[a])
	{
		b = 0;
		while (av[a][b])
		{
			if (!ft_isdigit(av[a][b]))
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

unsigned int	current_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	usleep_x(unsigned int sleep_time)
{
	unsigned int	x;

	x = current_time();
	while (x + sleep_time > current_time())
		usleep(10);
}
