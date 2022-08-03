/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lyfe_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:20:40 by moulmado          #+#    #+#             */
/*   Updated: 2022/08/03 16:09:33 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	start_eating(t_philo *philo)
{
	prepare_2_eat(philo);
	pthread_mutex_lock(&philo->death_check);
	if (philo->p_info->end)
		return ;
	philo->last_time_2_eat = current_time();
	msg_output(philo, "is eating");
	usleep(philo->p_info->time_2_eat * 1000);
	philo->times_has_eaten++;
	philo->fork->inuse = 0;
	philo->next->fork->inuse = 0;
	if (philo->times_has_eaten == philo->p_info->nb_must_eat)
		philo->p_info->eat_goal++;
	pthread_mutex_unlock(&philo->death_check);
}

static void	start_sleeping(t_philo *philo)
{
	if (philo->p_info->end)
		return ;
	msg_output(philo, "is sleeping");
	usleep_x(philo->p_info->time_2_sleep * 1000);
}

static void	start_thinking(t_philo *philo)
{
	if (philo->p_info->end)
		return ;
	msg_output(philo, "is thinking");
}

void	*lyfe_cycle(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_create(&philo->life_watcher, NULL, &death_watcher, philo);
	while (!philo->p_info->end)
	{
		start_eating(philo);
		start_sleeping(philo);
		start_thinking(philo);
	}
	return (NULL);
}