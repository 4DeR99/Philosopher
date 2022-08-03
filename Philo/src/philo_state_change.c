/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state_change.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:03:47 by moulmado          #+#    #+#             */
/*   Updated: 2022/08/03 14:59:00 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	msg_output(t_philo *philo, char	*status)
{
	pthread_mutex_t printing;

	if (philo->p_info->end)
		return ;
	pthread_mutex_init(&printing, NULL);
	pthread_mutex_lock(&printing);
	printf("%i %i %s\n", current_time() - philo->p_info->start_time,
		philo->philo_id, status);
	pthread_mutex_destroy(&printing);
}
