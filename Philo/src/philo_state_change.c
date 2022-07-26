/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state_change.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:03:47 by moulmado          #+#    #+#             */
/*   Updated: 2022/08/11 12:39:44 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	msg_output(t_philo *philo, char	*status, short ded)
{
	if (!philo->p_info->end)
	{
		pthread_mutex_lock(&philo->p_info->printing);
		printf("%i %i %s\n", current_time() - philo->p_info->start_time,
			philo->philo_id, status);
		if (ded)
			philo->p_info->end = 1;
		else
			pthread_mutex_unlock(&philo->p_info->printing);
	}
}
