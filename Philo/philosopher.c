/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:57:23 by moulmado          #+#    #+#             */
/*   Updated: 2022/07/27 14:16:03 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_info	*set_infos(int ac, char **av)
{
	t_info	*p_info;
	
	p_info = malloc(sizeof(t_info *));
	p_info->philo_nb = ft_atoi(av[1]);
	p_info->time_2_die = ft_atoi(av[2]);
	p_info->time_2_eat = ft_atoi(av[3]);
	p_info->time_2_sleep = ft_atoi(av[4]);
	p_info->nb_must_eat = -1;
	if (ac == 6)
		p_info->nb_must_eat = ft_atoi(av[5]);
	return (p_info);
}

void	create_philos(t_info *p_info, t_arg *p_arg)
{
	int 			index;
	pthread_t		*philo;
	
	p_info->start_time = current_time();
	index = 1;
	p_arg = lst_create(1, p_info);
	while (index < p_info->philo_nb)
	{
		lst_add(p_arg ,lst_create(index + 1, p_info));
		index++;
	}
	lst_add(p_arg, p_arg);
	index = 0;
	while (index < p_info->philo_nb)
	{
		pthread_create(philo, NULL, &routine, p_arg);
		pthread_detach(philo);
		index++;
	}
}

int	main(int ac, char **av)
{
	t_info	*p_info;
	t_arg	*p_arg;

	if (!parse(ac, av))
	{
		printf ("Error\n");
		return (0);
	}
	p_info = set_infos(ac, av);
	if (p_info->nb_must_eat == 0 || p_info->philo_nb == 0)
		return (0);
	create_philos(p_info, p_arg);
}