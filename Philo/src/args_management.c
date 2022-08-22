/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:34:45 by moulmado          #+#    #+#             */
/*   Updated: 2022/08/22 12:33:18 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static t_fork	*fork_create(void)
{
	t_fork			*fork;
	pthread_mutex_t	lock;

	if (pthread_mutex_init(&lock, NULL))
		return (putstr_fd_x("Failled to initate mutex\n", 2), NULL);
	fork = malloc(sizeof(t_fork));
	if (!fork)
		return (putstr_fd_x("Allocation error\n", 2), NULL);
	fork->inuse = 0;
	fork->last_user = 0;
	fork->lock = lock;
	return (fork);
}

t_philo	*lst_create(int n, t_info *p_info)
{
	t_philo			*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (putstr_fd_x("Allocation error\n", 2), NULL);
	philo->fork = fork_create();
	if (!philo->fork)
		return (NULL);
	philo->p_info = p_info;
	philo->last_time_2_eat = current_time();
	philo->philo_id = n;
	philo->next = NULL;
	return (philo);
}

t_philo	*ascending_philos(t_info *p_info)
{
	short	index;
	t_philo	*node;
	t_philo	*philo;

	index = 1;
	philo = lst_create(1, p_info);
	if (!philo)
		return (NULL);
	node = philo;
	while (index < p_info->philo_nb)
	{
		node->next = lst_create(index + 1, p_info);
		if (!node->next)
			return (NULL);
		node = node->next;
		index++;
	}
	node->next = philo;
	return (philo);
}
