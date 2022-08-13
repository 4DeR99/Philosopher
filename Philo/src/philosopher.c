/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:57:23 by moulmado          #+#    #+#             */
/*   Updated: 2022/08/13 13:49:41 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static t_info	*set_infos(int ac, char **av)
{
	t_info			*p_info;
	pthread_mutex_t	printing;

	if (pthread_mutex_init(&printing, NULL))
		return (putstr_fd_x("Failled to initate mutex\n", 2), NULL);
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

static t_philo	*create_philos(t_info *p_info)
{
	int 	index;
	t_philo	*philo;

	if (p_info->nb_must_eat == 0 || p_info->philo_nb == 0 || !p_info)
		return (NULL);
	p_info->start_time = current_time();
	philo = ascending_philos(p_info);
	if (!philo)
		return (NULL);
	index = 1;
	while (index <= p_info->philo_nb)
	{
		if (pthread_create(&philo->philo_thread, NULL, &lyfe_cycle, philo))
			return (putstr_fd_x("Failled to create thread\n", 2), NULL);
		if (pthread_detach(philo->philo_thread))
			return (putstr_fd_x("Failled to detach\n", 2), NULL);
		philo = philo->next;
		index++;
	}
	return (philo);
}

int	main(int ac, char **av)
{
	t_info	*p_info;
	t_philo	*philo;

	if (!parse(ac, av))
	{
		printf ("Error\n");
		return (0);
	}
	p_info = set_infos(ac, av);
	philo = create_philos(p_info);
	if (!philo)
	{
		destruction(philo, p_info);
		return (0);
	}
	while (!p_info->end)
		usleep(WAIT_TIME);
	destruction(philo, p_info);
}
