/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lyfe_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:20:40 by moulmado          #+#    #+#             */
/*   Updated: 2022/08/22 11:34:16 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	start_eating(t_philo *philo)
{
	prepare_2_eat(philo);
	if (philo->p_info->end)
		return ;
	philo->last_time_2_eat = current_time();
	msg_output(philo, "is eating", 0);
	usleep_x(philo->p_info->time_2_eat);
	philo->times_has_eaten++;
	philo->fork->inuse = 0;
	philo->next->fork->inuse = 0;
	if (philo->times_has_eaten == philo->p_info->nb_must_eat)
		philo->p_info->eat_goal++;
}

static void	start_sleeping(t_philo *philo)
{
	if (philo->p_info->end)
		return ;
	msg_output(philo, "is sleeping", 0);
	usleep_x(philo->p_info->time_2_sleep);
}

static void	start_thinking(t_philo *philo)
{
	if (philo->p_info->end)
		return ;
	msg_output(philo, "is thinking", 0);
}

void	*lyfe_cycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_create(&philo->life_watcher, NULL, &death_watcher, philo);
	while (!philo->p_info->end)
	{
		start_eating(philo);
		start_sleeping(philo);
		start_thinking(philo);
	}
	return (NULL);
}
