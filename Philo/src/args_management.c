/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:34:45 by moulmado          #+#    #+#             */
/*   Updated: 2022/08/03 15:49:00 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static t_fork	*fork_create(void)
{
	t_fork			*fork;
	pthread_mutex_t	lock;
	
	pthread_mutex_init(&lock, NULL);
	fork = malloc(sizeof(t_fork *));
	fork->inuse = 0;
	fork->last_user = 0;
	fork->lock = lock;
	return (fork);
}

t_philo	*lst_create(int n, t_info *p_info)
{
	t_philo			*philo;

	philo = malloc(sizeof(t_philo *));
	philo->fork = fork_create();
	philo->last_time_2_eat = current_time();
	philo->philo_id = n;
	philo->p_info = p_info;
	philo->next = NULL;
	return (philo);
}
