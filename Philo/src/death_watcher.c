/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_watcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:41:35 by moulmado          #+#    #+#             */
/*   Updated: 2022/08/22 11:33:57 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	confirme_death(t_philo *philo)
{
	unsigned int	starving;

	starving = current_time() - philo->last_time_2_eat;
	if (starving > philo->p_info->time_2_die && !philo->p_info->end)
		msg_output(philo, "died", 1);
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
			pthread_mutex_lock(&philo->p_info->printing);
		}
		confirme_death(philo);
		usleep(WAIT_TIME);
	}
	return (NULL);
}
