/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taking_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 09:34:14 by moulmado          #+#    #+#             */
/*   Updated: 2022/08/11 12:32:58 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

short	fork_istaken(t_philo *philo)
{
	return (philo->next->fork->inuse + philo->fork->inuse);
}

short	is_last_user(t_philo *philo)
{
	if (philo->philo_id == philo->fork->last_user
		|| philo->philo_id == philo->next->fork->last_user)
		return (1);
	return (0);
}

void	take_forks(t_philo *philo)
{
	philo->fork->last_user = philo->philo_id;
	philo->next->fork->last_user = philo->philo_id;
	philo->fork->inuse = 1;
	msg_output(philo, "has taken a fork", 0);
	philo->next->fork->inuse = 1;
	msg_output(philo, "has taken a fork", 0);
}

static short	try_taking_fork(t_philo *philo)
{
	short	re;

	re = 0;
	if (philo->philo_id == 1)
	{
		pthread_mutex_lock(&philo->next->fork->lock);
		pthread_mutex_lock(&philo->fork->lock);
	}
	else
	{
		pthread_mutex_lock(&philo->fork->lock);
		pthread_mutex_lock(&philo->next->fork->lock);
	}
	if (!fork_istaken(philo) && !is_last_user(philo))
	{
		take_forks(philo);
		re = 1;
	}
	pthread_mutex_unlock(&philo->next->fork->lock);
	pthread_mutex_unlock(&philo->fork->lock);
	return (re);
}

void	prepare_2_eat(t_philo *philo)
{
	while (!philo->p_info->end && !try_taking_fork(philo))
		usleep(WAIT_TIME);
}