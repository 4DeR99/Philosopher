/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_watcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:41:35 by moulmado          #+#    #+#             */
/*   Updated: 2022/08/03 14:58:20 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	confirme_death(t_philo *philo)
{
	short	starving;

	pthread_mutex_lock(&philo->death_check);
	starving = current_time() - philo->p_info->start_time;
	if (starving > philo->p_info->time_2_die)
	{
		msg_output(philo, "is ded");
		philo->p_info->end = 1;
	}
	pthread_mutex_unlock(&philo->death_check);
}

void	*death_watcher(void	*arg)
{
	t_philo	*philo;

	philo = arg;
	while (!philo->p_info->end)
	{
		if (philo->p_info->eat_goal == philo->p_info->philo_nb)
		{
			philo->p_info->end = 1;
			return (NULL);
		}
		confirme_death(philo);
		usleep(WAIT_TIME);
	}
	return (NULL);
}