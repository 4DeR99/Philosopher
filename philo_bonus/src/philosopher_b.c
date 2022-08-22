/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:59 by moulmado          #+#    #+#             */
/*   Updated: 2022/08/16 14:24:00 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_b.h"

static t_info	*set_infos(int ac, char **av)
{
	t_info			*p_info;

	p_info = malloc(sizeof(t_info));
	if (!p_info)
		return (putstr_fd_x("Allocation error\n", 2), NULL);
	p_info->end = false;
	p_info->eat_goal = 0;
	p_info->philo_nb = ft_atoi(av[1]);
	p_info->time_2_die = ft_atoi(av[2]);
	p_info->time_2_eat = ft_atoi(av[3]);
	p_info->time_2_sleep = ft_atoi(av[4]);
	p_info->nb_must_eat = -1;
	p_info->printing = printing;
	if (ac == 6)
		p_info->nb_must_eat = ft_atoi(av[5]);
	return (p_info);
}

int	main(int ac, char **av)
{
	t_info	*p_info;

	if (!parse(ac, av))
	{
		printf ("Error\n");
		return (0);
	}
}